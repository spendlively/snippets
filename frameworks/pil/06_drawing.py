from PIL import Image, ImageDraw, ImageFont

# Создаем белый квадрат
img = Image.new('RGBA', (200, 200), 'white')
idraw = ImageDraw.Draw(img)

idraw.rectangle((10, 10, 100, 100), fill='blue')

# ls /usr/share/fonts/truetype/
text = "Hello, World!"
font = ImageFont.truetype("DejaVuSerif.ttf", size=12)
idraw.text((10, 10), text, font=font)

img.save('/home/spendlively/common/downloads/drawing.png')
