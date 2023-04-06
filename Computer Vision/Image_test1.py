from PIL import Image

img = Image.open("./suzume no tojimari.bmp")

img.show()

img1=img.transpose(Image.FLIP_LEFT_RIGHT)

img1.save("./output_test/Image_transpose_FLIP_LEFT_RIGHT.bmp")

img2=img.transpose(Image.FLIP_TOP_BOTTOM)

img2.save("./output_test/Image_transpose_FLIP_TOP_BOTTOM.bmp")

img3=img.rotate(180)

img3.save("./output_test/Image_rotate_180.bmp")
