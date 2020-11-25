import cv2

img1 = cv2.imread('/home/spendlively/common/downloads/1.jpg')
img2 = cv2.imread('/home/spendlively/common/downloads/2.jpg')

img1 = cv2.resize(img1, (512, 512))
img2 = cv2.resize(img2, (512, 512))

# dst = cv2.add(img1, img2)
dst = cv2.addWeighted(img1, 0.2, img2, 0.8, 0)

cv2.imshow('image', dst)

cv2.waitKey(0)
cv2.destroyAllWindows()
