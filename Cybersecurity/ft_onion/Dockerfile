FROM ubuntu:24.04

RUN apt update && apt install -y nginx openssh-server tor curl

COPY html/index.html /var/www/html/index.html

COPY html/images /var/www/html/images

RUN rm -f /var/www/html/index.nginx-debian.html

COPY nginx/nginx.conf /etc/nginx/nginx.conf

COPY start.sh /start.sh

COPY ssh/sshd_config /etc/ssh/sshd_config

COPY tor/torrc /etc/tor/torrc

RUN useradd -m -s /bin/bash fassa && \
    usermod -aG sudo fassa

RUN mkdir -p /home/fassa/.ssh

COPY ssh/authorized_keys /home/fassa/.ssh/authorized_keys

RUN chmod 700 /home/fassa/.ssh && \
    chmod 600 /home/fassa/.ssh/authorized_keys && \
    chown -R fassa:fassa /home/fassa/.ssh

RUN chmod +x /start.sh

CMD ["/start.sh"]