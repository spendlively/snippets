from PIL import Image

image = Image.open('/home/spendlively/common/downloads/123.jpg')

# 1. Непропорциональное изменение размера
non_proportional = image.resize((100, 100), Image.ANTIALIAS)
non_proportional.save('/home/spendlively/common/downloads/123_non_prop_resize.jpg', 'jpeg')

# 2. Пропорциональное изменение размера по заданной ширине
width, height = image.size
new_width = 680
new_height = int(new_width * height / width)
width_image = image.resize((new_width, new_height), Image.ANTIALIAS)
width_image.save('/home/spendlively/common/downloads/123_prop_resize_by_given_width.jpg', 'jpeg')

# 3. Пропорциональное изменение размера по заданной высоте
width, height = image.size
new_height = 680
new_width = int(new_height * width / height)
height_image = image.resize((new_width, new_height), Image.ANTIALIAS)
height_image.save('/home/spendlively/common/downloads/123_prop_resize_by_given_height.jpg', 'jpeg')
