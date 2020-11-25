import cv2

img = cv2.imread('/home/spendlively/common/downloads/1.jpg')

height, width, channels = img.shape

# resize by given width
new_width = 512
new_height = int(new_width * height / width)

img = cv2.resize(img, (new_width, new_height))

# interpolation
# img = cv2.resize(img, (new_width, new_height), interpolation=cv2.INTER_NEAREST)
# img = cv2.resize(img, (new_width, new_height), interpolation=cv2.INTER_LINEAR)
# img = cv2.resize(img, (new_width, new_height), interpolation=cv2.INTER_AREA)
# img = cv2.resize(img, (new_width, new_height), interpolation=cv2.INTER_CUBIC)
# img = cv2.resize(img, (new_width, new_height), interpolation=cv2.INTER_LANCZOS4)

# cv2.imwrite('/home/spendlively/common/downloads/1_copy.jpg', img)

cv2.imshow('image', img)

cv2.waitKey(0)
cv2.destroyAllWindows()
