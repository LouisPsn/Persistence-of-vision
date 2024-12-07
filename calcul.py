import numpy as np
from PIL import Image


def print_tab(values):
    f = open("buffer.txt", "a")
    
    i = 0
    for value in values:
        f.write("ring_buffer_put_2(&rb, 0b")
        for j in range(16):
            f.write(str(int(value[j])))    
        f.write(", ")
        f.write(str(i))
        f.write(");\n")
        i += 1
    


def main(path="/home/louis/Documents/3A/Système Embarquée/Projet/Persistence-of-vision/photo_2024-12-02_13-59-21.jpg"):
    
    number_of_frame = 60

    img = Image.open(path)
    numpy_data = np.asarray(img, dtype=np.uint16)

    shape = numpy_data.shape

    middle = (int(numpy_data.shape[0]/2), int(numpy_data.shape[0]/2))
    
    numpy_binary = np.zeros((shape[0], shape[1]))

    for i in range(shape[0]):
        for j in range(shape[1]):
            if (numpy_data[i][j][0] + numpy_data[i][j][1] + numpy_data[i][j][2])/3 > 255/2:
                numpy_binary[i][j] = 1
            else:
                numpy_binary[i][j] = 0

    values = np.zeros((number_of_frame, 16))

    r = np.array([0.15, 0.205555556, 0.261111111, 0.322222222, 0.377777778, 0.433333333, 0.488888889, 0.544444444, 0.6, 0.661111111, 0.716666667, 0.772222222, 0.827777778, 0.883333333, 0.938888889, 1.0])

    theta_array = np.linspace(0, 2*np.pi, number_of_frame)

    counter = 0

    for theta in theta_array:
        for i in range(16):
            x = r[i]*shape[0]/2*np.cos(theta)
            y = r[i]*shape[1]/2*np.sin(theta)

            values[counter][i] = int(numpy_binary[int(y) + middle[0]][-int(x) + middle[0]])
        counter += 1

    print_tab(values)


main()