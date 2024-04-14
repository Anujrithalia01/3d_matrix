#include<iostream>


int main() {

	int choice;

	double tx, ty, tz, sx, sy, sz, angle, x, y, z;

	do {
        std::cout << "Menu:\n";
        std::cout << "1. Translate\n";
        std::cout << "2. Scale\n";
        std::cout << "3. Skew\n";
        std::cout << "4. Display Matrix\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            float tx, ty, tz;
            std::cout << "Enter translation values (tx ty tz): ";
            std::cin >> tx >> ty >> tz;
            transform.translate(matrix, tx, ty, tz);
            break;
        case 2:
            float sx, sy, sz;
            std::cout << "Enter scaling factors (sx sy sz): ";
            std::cin >> sx >> sy >> sz;
            transform.scale(matrix, sx, sy, sz);
            break;
        case 3:
            float skewXY, skewXZ, skewYZ;
            std::cout << "Enter skewing factors (xy xz yz): ";
            std::cin >> skewXY >> skewXZ >> skewYZ;
            transform.skew(matrix, skewXY, skewXZ, skewYZ);
            break;
        case 4:
            std::cout << "Transformed Matrix:\n";
            matrix.display();
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

        return 0;
}