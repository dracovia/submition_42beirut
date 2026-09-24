*This project has been created as part of the 42 curriculum by mfassad.*

# Cybersecurity - Arachnida

## Description

Arachnida is an introductory cybersecurity project focused on **web scraping** and **image metadata analysis**.

The project contains two programs:

- `spider` — recursively extracts and downloads images from websites.
- `scorpion` — analyzes image files and displays their metadata.

The project introduces concepts such as:

- HTTP requests
- HTML parsing
- Recursive web crawling
- URL handling
- File downloading
- Command-line argument parsing
- EXIF metadata
- GPS metadata
- Image properties
- Filesystem metadata
- Error handling

The project also demonstrates how metadata can reveal information about how, when, and where an image was created.

## Exercises

### Exercise 1 — Spider

`spider` is a command-line web crawler that extracts images from a website.

Basic usage:

```bash
./spider URL
```

The program supports the following options:

- `-r` — recursively follows links and downloads images from linked pages.
- `-l N` — sets the maximum recursion depth.
- `-p PATH` — sets the directory where downloaded images are saved.

If `-l` is not specified while recursion is enabled, the default maximum depth is:

```text
5
```

If `-p` is not specified, downloaded images are stored in:

```text
./data/
```

The following image formats are supported:

- `.jpg`
- `.jpeg`
- `.png`
- `.gif`
- `.bmp`

This exercise introduces:

- HTTP requests with `requests`
- Parsing HTML with `HTMLParser`
- Extracting `<img src="">`
- Extracting `<a href="">`
- Converting relative URLs to absolute URLs
- Recursive crawling
- Recursion depth control
- Avoiding repeated page visits
- Avoiding duplicate image downloads
- Handling filename collisions
- Creating output directories
- Network error handling
- Filesystem error handling

The crawler only follows HTTP and HTTPS links.

Visited pages are tracked to prevent recursive loops such as:

```text
Page A -> Page B -> Page A -> Page B -> ...
```

Downloaded image URLs are also tracked to avoid downloading the same resource repeatedly.

### Exercise 2 — Scorpion

`scorpion` analyzes one or more image files and displays their metadata.

Usage:

```bash
./scorpion FILE1 [FILE2 ...]
```

Example:

```bash
./scorpion image.jpg
```

Multiple files can also be analyzed:

```bash
./scorpion image1.jpg image2.png image3.bmp
```

For each supported image, Scorpion displays basic information such as:

- Image format
- Width and height
- Color mode
- File size
- Last modification time

It also extracts available metadata such as:

- EXIF information
- EXIF Sub-IFD information
- Original creation date
- Software information
- GPS latitude
- GPS longitude
- PNG metadata
- JPEG/JFIF metadata

Large binary metadata values are summarized instead of printing thousands of raw bytes.

Example output:

```text
File: image.jpg
Format: JPEG
Size: 1280 x 720
Mode: RGB

EXIF:
  Software: Windows 11

EXIF Sub-IFD:
  DateTimeOriginal: 2026:05:08 16:34:59

GPS:
  GPSLatitudeRef: N
  GPSLatitude: (33.0, 53.0, 30.96383747)
  GPSLongitudeRef: E
  GPSLongitude: (35.0, 30.0, 21.28898666)

File metadata:
  File size: 159854 bytes
```

This exercise introduces:

- Image parsing with Pillow
- EXIF tags
- Nested EXIF IFD structures
- GPS metadata
- Image metadata dictionaries
- Filesystem metadata
- Processing multiple files
- Handling corrupted images
- Handling missing files
- Handling unsupported formats

## Project Structure

```text
arachnida/
├── README.md
├── spider
├── scorpion
└── requirements.txt
```

Downloaded images are stored in the default directory:

```text
data/
```

unless another path is specified using `-p`.

## Instructions

### Requirements

You need:

- Python 3
- pip
- A Unix-like environment such as Linux or macOS

The project uses:

- `requests`
- `Pillow`

Install the dependencies with:

```bash
python3 -m pip install -r requirements.txt
```

The `requirements.txt` file contains:

```text
requests
Pillow
```

Make sure both programs are executable:

```bash
chmod +x spider scorpion
```

Both programs use:

```python
#!/usr/bin/env python3
```

as their interpreter declaration.

### Spider

Basic execution:

```bash
./spider "https://www.python.org/"
```

Recursive download:

```bash
./spider -r "https://www.python.org/"
```

Recursive download with a maximum depth:

```bash
./spider -r -l 2 "https://www.python.org/"
```

Specify another output directory:

```bash
./spider -p images "https://www.python.org/"
```

Combine options:

```bash
./spider -r -l 2 -p images "https://www.python.org/"
```

### Scorpion

Analyze one image:

```bash
./scorpion image.jpg
```

Analyze several images:

```bash
./scorpion image1.jpg image2.png image3.bmp
```

## Usage Examples

### Spider

Download images from only the provided page:

```bash
./spider "https://www.python.org/"
```

Example output:

```text
[Depth 0] https://www.python.org/
Downloaded: ./data/python-logo.png
```

Download recursively to depth 1:

```bash
./spider -r -l 1 "https://www.python.org/"
```

Example:

```text
[Depth 0] https://www.python.org/
Downloaded: ./data/python-logo.png

[Depth 1] https://www.python.org/psf/
Downloaded: ./data/psf-logo.png
```

Save images to another directory:

```bash
./spider -p my_images "https://www.python.org/"
```

### Scorpion

Analyze a PNG:

```bash
./scorpion screenshot.png
```

Example:

```text
File: screenshot.png
Format: PNG
Size: 400 x 305
Mode: RGBA

EXIF: No EXIF metadata found

Other metadata:
  srgb: 0
  gamma: 0.45455
  dpi: (119.9896, 119.9896)
```

Analyze a JPEG containing EXIF information:

```bash
./scorpion photo.jpg
```

Possible output:

```text
File: photo.jpg
Format: JPEG
Size: 1280 x 720
Mode: RGB

EXIF:
  Software: Windows 11

EXIF Sub-IFD:
  DateTimeOriginal: 2026:05:08 16:34:59

GPS:
  GPSLatitudeRef: N
  GPSLatitude: (...)
  GPSLongitudeRef: E
  GPSLongitude: (...)
```

## Error Handling

Spider handles errors such as:

- Invalid URL schemes
- Unreachable websites
- DNS failures
- HTTP request failures
- Invalid recursion depth
- Invalid output paths
- Filesystem errors
- User interruption with `Ctrl+C`

Example:

```text
Failed to crawl https://example.invalid: ...
```

Scorpion handles:

- Missing files
- Unsupported extensions
- Corrupted image files
- Images without EXIF metadata

Example:

```text
File: fake.jpg
Error reading image: cannot identify image file 'fake.jpg'
```

When several files are provided, an error in one file does not prevent the remaining files from being analyzed.

## Technical Choices

- Python was used to keep the focus on web scraping and metadata analysis.
- `requests` is used only for HTTP communication.
- Python's built-in `HTMLParser` is used to parse HTML.
- `urllib.parse` is used to resolve and analyze URLs.
- `argparse` is used for command-line options.
- Pillow is used to inspect supported image formats and metadata.
- A `set` is used to track visited pages and avoid recursive loops.
- Another `set` tracks downloaded image URLs.
- Filename collisions are handled without overwriting previously downloaded files.
- Only HTTP and HTTPS links are crawled.
- Raw EXIF byte blocks are summarized instead of fully printed.
- Filesystem creation time is only displayed when the platform exposes a real creation timestamp.
- Tools such as `wget` and `scrapy` are not used.

## Resources

The following references were used to understand the concepts required by the project:

- The official **42 Cybersecurity Arachnida subject**
- Peer discussions and the 42 intranet learning material
- geeks for geeks all info about imports used in this project 

### Use of AI

AI was used as a learning and review tool for:

- Clarifying Python concepts related to HTTP requests, HTML parsing, recursion, URL parsing, and file handling.
- Explaining image metadata concepts such as EXIF, IFD structures, GPS metadata, and filesystem timestamps.
- Explaining errors encountered during development.
- Reviewing program logic and identifying possible edge cases.
- Testing reasoning around recursion depth, duplicate URLs, filename collisions, invalid paths, and corrupted files.
- Improving the structure and wording of this README.
