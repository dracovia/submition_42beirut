#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
	enum
	{
		ADD,
		MULTI,
		VAL
	}	type;
	int			val;
	struct node	*l;
	struct node	*r;
}	node;

node	*new_node(node n)
{
	node	*ret;

	ret = calloc(1, sizeof(node));
	if (!ret)
		return (NULL);
	*ret = n;
	return (ret);
}

void	destroy_tree(node *n)
{
	if (!n)
		return ;
	if (n->type != VAL)
	{
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

int	accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int	expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

/*
** primary:
**     digit
**     '(' expression ')'
*/
static node	*parse_primary(char **s);

/*
** multiplication:
**     primary ('*' primary)*
*/
static node	*parse_multiplication(char **s);

/*
** expression:
**     multiplication ('+' multiplication)*
*/
static node	*parse_expression(char **s);

static node	*parse_primary(char **s)
{
	node	*ret;

	if (isdigit((unsigned char)**s))
	{
		ret = new_node((node){
				.type = VAL,
				.val = **s - '0',
				.l = NULL,
				.r = NULL
			});
		if (!ret)
			return (NULL);
		(*s)++;
		return (ret);
	}
	if (accept(s, '('))
	{
		ret = parse_expression(s);
		if (!ret)
			return (NULL);
		if (!expect(s, ')'))
		{
			destroy_tree(ret);
			return (NULL);
		}
		return (ret);
	}
	unexpected(**s);
	return (NULL);
}

static node	*parse_multiplication(char **s)
{
	node	*left;
	node	*right;
	node	*parent;

	left = parse_primary(s);
	if (!left)
		return (NULL);
	while (accept(s, '*'))
	{
		right = parse_primary(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		parent = new_node((node){
				.type = MULTI,
				.val = 0,
				.l = left,
				.r = right
			});
		if (!parent)
		{
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}
		left = parent;
	}
	return (left);
}
static node	*parse_expression(char **s)
{
	node	*left;
	node	*right;
	node	*parent;

	left = parse_multiplication(s);
	if (!left)
		return (NULL);
	while (accept(s, '+'))
	{
		right = parse_multiplication(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		parent = new_node((node){
				.type = ADD,
				.val = 0,
				.l = left,
				.r = right
			});
		if (!parent)
		{
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}
		left = parent;
	}
	return (left);
}

node	*parse_expr(char *s)
{
	node	*ret;

	ret = parse_expression(&s);
	if (!ret)
		return (NULL);
	if (*s)
	{
		unexpected(*s);
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}

int	eval_tree(node *tree)
{
	if (tree->type == ADD)
		return (eval_tree(tree->l) + eval_tree(tree->r));
	if (tree->type == MULTI)
		return (eval_tree(tree->l) * eval_tree(tree->r));
	return (tree->val);
}

int	main(int argc, char **argv)
{
	node	*tree;

	if (argc != 2)
		return (1);
	tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}