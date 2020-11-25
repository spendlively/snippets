from PIL import Image

image = Image.open('/home/spendlively/common/downloads/123.jpg')

width, height = image.size
print(width, height)

exif = image._getexif()
print(exif)

r, g, b = image.split()
print(r, g, b)

histogram = image.histogram()
print(histogram)
