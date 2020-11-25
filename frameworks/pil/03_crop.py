from PIL import Image

image = Image.open('/home/spendlively/common/downloads/123.jpg')
width, height = image.size
cropped = image.crop((0, 0, width / 2, height / 2))
cropped.save('/home/spendlively/common/downloads/123_crop.jpg')
