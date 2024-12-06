from PIL import Image, ImageFilter

before = Image.open("nature.jpg")
after = before.filter(ImageFilter.SMOOTH)
after.save("nature2.jpg")
