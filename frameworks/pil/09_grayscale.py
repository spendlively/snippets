from PIL import Image
import sys

try:
    image = Image.open("/home/spendlively/common/downloads/123.jpg")
except IOError:
    print("Unable to load image")
    sys.exit(1)

grayscale = image.convert('L')
grayscale.show()
