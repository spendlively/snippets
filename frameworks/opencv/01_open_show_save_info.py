import cv2

flag = cv2.IMREAD_COLOR  # 0
# flag = cv2.IMREAD_GRAYSCALE  # 1
# flag = cv2.IMREAD_UNCHANGED  # -1

img = cv2.imread('/home/spendlively/common/downloads/1.jpg', flag)

# sizes and channels
print(img.shape)
# number of pixels
print(img.size)
# image data type
print(img.dtype)

cv2.imshow('image', img)
k = cv2.waitKey(0) & 0xFF

if k == 27:
    cv2.destroyAllWindows()
elif k == ord('s'):
    cv2.imwrite('/home/spendlively/common/downloads/1_copy.jpg', img)
    cv2.destroyAllWindows()
