#include<iostream>
#include<vector>
#include"Matrice.h"
#include"Translation.h"
#include"Scaling.h"
#include"Rotation.h"
#include"Skewing.h"

int main() {

    int choice = 0; int points;
    char axis;
    double tx, ty, tz, sx, sy, sz, angle, scalar;

    do {

        std::cout << "Select a transformation:" << std::endl;
        std::cout << "1. Translation" << std::endl;
        std::cout << "2. Scaling" << std::endl;
        std::cout << "3. Scalar Multiplciation" << std::endl;
        std::cout << "4. Transpose" << std::endl;
        std::cout << "5. Rotation" << std::endl;
        std::cout << "6. Skewing" << std::endl;
        std::cout << "7. Inverse" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

        std::cin >> choice;

        switch (choice) {

        case 1: {

            std::cout << "Enter the number of 3d points to be Translated: " << std::endl;
            std::cin >> points;

            Translation t(points);
            std::cout << "Enter translation values (tx, ty, tz): " << std::endl;
            std::cin >> tx >> ty >> tz;
            t.translation(tx, ty, tz);
            break;
        }

        case 2: {

            std::cout << "Enter the number of 3d points to be Scaled: " << std::endl;
            std::cin >> points;

            Scaling s(points);
            std::cout << "Enter scaling values (sx, sy, sz): " << std::endl;
            std::cin >> sx >> sy >> sz;
            s.scaling(sx, sy, sz);
            break;
        }

        case 3: {

            int row, col;                       

            std::cout << "Enter the value of rows of Matrix -->" << std::endl;
            std::cin >> row;

            std::cout << "Enter the value of columns of Matrix -->" << std::endl;
            std::cin >> col;

            Matrice matrix_1(row, col);
            std::cout << "Enter the elements of Matrix :" << std::endl;
            matrix_1.set_value();
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Enter the value for Scaler multiplication" << std::endl;
            std::cin >> scalar;
            (matrix_1 * scalar).print_it();
            break;
        }

        case 4: {

            int row, col;                       

            std::cout << "Enter the value of rows of Matrix -->" << std::endl;
            std::cin >> row;

            std::cout << "Enter the value of columns of Matrix -->" << std::endl;
            std::cin >> col;

            Matrice matrix(row, col);
            std::cout << "Enter the elements of Matrix :" << std::endl;
            matrix.set_value();
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "The transposed Matrix is: " << std::endl;

            (matrix.transpose(matrix)).print_it();
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

            break;
        }
        case 5: {

            std::cout << "Enter the number of 3d points to be Rotated: " << std::endl;
            std::cin >> points;
            Rotation r(points);

            std::cout << "Enter rotation angle (degrees) and axis (x , y or z): ";
            std::cin >> angle >> axis;
            r.rotation(angle, axis);
            //r.print();
            break;
        }
        case 6: {

            std::cout << "Enter the number of 3d points to be Skewed: " << std::endl;
            std::cin >> points;

            Skewing s(points);
            std::cout << "Enter skewing axis and skewing factors (sx, sy, sz): " << std::endl;
            std::cin>>axis >> sx >> sy >> sz;
            s.skewing(axis, sx, sy, sz);
            break;
        }
        case 7: {

            int row, col;                      

            std::cout << "Enter the value of rows of Matrix -->" << std::endl;
            std::cin >> row;

            std::cout << "Enter the value of columns of Matrix -->" << std::endl;
            std::cin >> col;

            Matrice matrix(row, col);
            std::cout << "Enter the elements of Matrix :" << std::endl;
            matrix.set_value();
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "The inverse Matrix is: " << std::endl;

            (matrix.inverse(matrix)).print_it();
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

            break;
        }

        case 8:
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 8);

}