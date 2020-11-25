from PIL import Image

image = Image.open('/home/spendlively/common/downloads/123.jpg')
rotated = image.rotate(180)
rotated.save('/home/spendlively/common/downloads/123_crop.jpg')
