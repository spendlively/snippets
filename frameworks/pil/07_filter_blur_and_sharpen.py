from PIL import Image, ImageDraw, ImageFont, ImageFilter

image = Image.open('/home/spendlively/common/downloads/123.jpg')

BLUR = image.filter(ImageFilter.BLUR)
BLUR.save('/home/spendlively/common/downloads/filter/BLUR.jpg')

SHARPEN = image.filter(ImageFilter.SHARPEN)
SHARPEN.save('/home/spendlively/common/downloads/filter/SHARPEN.jpg')

FIND_EDGES = image.filter(ImageFilter.FIND_EDGES)
FIND_EDGES.save('/home/spendlively/common/downloads/filter/FIND_EDGES.jpg')

# BoxBlur = image.filter(ImageFilter.BoxBlur)
# BoxBlur.save('/home/spendlively/common/downloads/filter/BoxBlur.jpg')

# BuiltinFilter = image.filter(ImageFilter.BuiltinFilter)
# BuiltinFilter.save('/home/spendlively/common/downloads/filter/BuiltinFilter.jpg')

# Color3DLUT = image.filter(ImageFilter.Color3DLUT)
# Color3DLUT.save('/home/spendlively/common/downloads/filter/Color3DLUT.jpg')

CONTOUR = image.filter(ImageFilter.CONTOUR)
CONTOUR.save('/home/spendlively/common/downloads/filter/CONTOUR.jpg')

DETAIL = image.filter(ImageFilter.DETAIL)
DETAIL.save('/home/spendlively/common/downloads/filter/DETAIL.jpg')

EDGE_ENHANCE = image.filter(ImageFilter.EDGE_ENHANCE)
EDGE_ENHANCE.save('/home/spendlively/common/downloads/filter/EDGE_ENHANCE.jpg')

EDGE_ENHANCE_MORE = image.filter(ImageFilter.EDGE_ENHANCE_MORE)
EDGE_ENHANCE_MORE.save('/home/spendlively/common/downloads/filter/EDGE_ENHANCE_MORE.jpg')

EMBOSS = image.filter(ImageFilter.EMBOSS)
EMBOSS.save('/home/spendlively/common/downloads/filter/EMBOSS.jpg')

GaussianBlur = image.filter(ImageFilter.GaussianBlur)
GaussianBlur.save('/home/spendlively/common/downloads/filter/GaussianBlur.jpg')

# Kernel = image.filter(ImageFilter.Kernel)
# Kernel.save('/home/spendlively/common/downloads/filter/Kernel.jpg')

MaxFilter = image.filter(ImageFilter.MaxFilter)
MaxFilter.save('/home/spendlively/common/downloads/filter/MaxFilter.jpg')

MedianFilter = image.filter(ImageFilter.MedianFilter)
MedianFilter.save('/home/spendlively/common/downloads/filter/MedianFilter.jpg')

MinFilter = image.filter(ImageFilter.MinFilter)
MinFilter.save('/home/spendlively/common/downloads/filter/MinFilter.jpg')

ModeFilter = image.filter(ImageFilter.ModeFilter)
ModeFilter.save('/home/spendlively/common/downloads/filter/ModeFilter.jpg')

# MultibandFilter = image.filter(ImageFilter.MultibandFilter)
# MultibandFilter.save('/home/spendlively/common/downloads/filter/MultibandFilter.jpg')

# RankFilter = image.filter(ImageFilter.RankFilter)
# RankFilter.save('/home/spendlively/common/downloads/filter/RankFilter.jpg')

SMOOTH = image.filter(ImageFilter.SMOOTH)
SMOOTH.save('/home/spendlively/common/downloads/filter/SMOOTH.jpg')

SMOOTH_MORE = image.filter(ImageFilter.SMOOTH_MORE)
SMOOTH_MORE.save('/home/spendlively/common/downloads/filter/SMOOTH_MORE.jpg')

UnsharpMask = image.filter(ImageFilter.UnsharpMask)
UnsharpMask.save('/home/spendlively/common/downloads/filter/UnsharpMask.jpg')
