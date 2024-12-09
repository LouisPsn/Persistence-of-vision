import numpy as np
from PIL import Image


def print_tab(values):
    f = open("buffer.txt", "w")
    
    i = 0
    for value in values:
        f.write("ring_buffer_put_2(&rb, 0b")
        for j in range(15, -1, -1):
            f.write(str(int(value[j])))    
        f.write(", ")
        f.write(str(i))
        f.write(");\n")
        i += 1
    


def main(path="penta-4.jpg"):
    
    number_of_frame = 100

    img = Image.open(path)
    numpy_data = np.asarray(img, dtype=np.uint16)

    shape = numpy_data.shape

    middle = (int(numpy_data.shape[0]/2), int(numpy_data.shape[1]/2))
    

    if len(shape) > 2:
        numpy_binary = np.zeros((shape[0], shape[1]))

        for i in range(shape[0]):
            for j in range(shape[1]):
                if (numpy_data[i][j][0] + numpy_data[i][j][1] + numpy_data[i][j][2])/3 > 255/1.5:
                    numpy_binary[i][j] = 1
                else:
                    numpy_binary[i][j] = 0

    else:
        numpy_binary = numpy_data
        
        shape = numpy_binary.shape
        for i in range(shape[0]):
            for j in range(shape[1]):
                if numpy_binary[i][j] == 2:
                    numpy_binary[i][j] = 0

    # print(numpy_binary)

    values = np.zeros((number_of_frame, 16))

    r = np.array([0.15, 0.205555556, 0.261111111, 0.322222222, 0.377777778, 0.433333333, 0.488888889, 0.544444444, 0.6, 0.661111111, 0.716666667, 0.772222222, 0.827777778, 0.883333333, 0.938888889, 1.0])

    theta_array = np.linspace(0, 2*np.pi, number_of_frame)

    counter = 0

    for theta in theta_array:
        for i in range(16):
            x = int(r[i]*shape[0]/2*np.cos(theta))
            y = int(-r[i]*shape[1]/2*np.sin(theta))
            
            values[counter][i] = numpy_binary[middle[0] - 1 - x][middle[1] - 1 + y]
        
        counter += 1

    print_tab(values)


main()