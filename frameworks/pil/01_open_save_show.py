import sys

from PIL import Image

try:
    image = Image.open("/home/spendlively/common/downloads/123.jpg")
except IOError:
    print("Unable to load image")
    sys.exit(1)

try:
    image.save('/home/spendlively/common/downloads/123_crop.jpg', 'jpeg')
except IOError:
    print("Unable to save image")
    sys.exit(1)

image.show()
