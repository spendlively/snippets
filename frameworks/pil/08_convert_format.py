import sys

from PIL import Image

try:
    image = Image.open('/home/spendlively/common/downloads/123.jpg')
except IOError:
    print("Unable to load image")
    sys.exit(1)

image.save('/home/spendlively/common/downloads/123.png', 'png')
