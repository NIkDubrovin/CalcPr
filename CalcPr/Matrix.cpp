#include "Matrix.h"
#include "Calc.h"


matrix createMatrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = new double* [rows];
    for (int i = 0; i < rows; i++) {
        m.data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = 0;
        }
    }
    return m;
}


matrix deleteMatrix(matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        delete[] m.data[i];
    }
    delete[] m.data;
    m.rows = 0;
    m.cols = 0;
    return m;
}


void inputMatrix(matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            cout << "������� �������� �������� [" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.data[i][j];
        }
    }
}


void outputMatrix(matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            cout << m.data[i][j] << "\t";
        }
        cout << endl;
    }
}


double detMatrix(matrix& m) {
    if (m.rows != m.cols) {
        cout << "������� �� ����������!" << endl;
        return 0;
    }
    if (m.rows == 1) {
        return m.data[0][0];
    }
    double det = 0;
    matrix temp = createMatrix(m.rows - 1, m.cols - 1);
    for (int k = 0; k < m.cols; k++) {
        int i = 0, j = 0;
        for (int row = 1; row < m.rows; row++) {
            for (int col = 0; col < m.cols; col++) {
                if (col == k) {
                    continue;
                }
                temp.data[i][j] = m.data[row][col];
                j++;
                if (j == m.cols - 1) {
                    i++;
                    j = 0;
                }
            }
        }
        det += pow(-1.0, k) * m.data[0][k] * detMatrix(temp);
    }
    deleteMatrix(temp);
    return det;
}


matrix inverseMatrix(matrix& m) {
    if (m.rows != m.cols) {
        cout << "������� �� ����������!" << endl;
        return createMatrix(0, 0);
    }
    double det = detMatrix(m);
    if (det == 0) {
        cout << "������������ ����� 0, �������� ������� �� ����������!" << endl;
        return createMatrix(0, 0);
    }
    matrix inv = createMatrix(m.rows, m.cols);
    matrix temp = createMatrix(m.rows - 1, m.cols - 1);
    for (int j = 0; j < m.cols; j++) {
        for (int i = 0; i < m.rows; i++) {
            int ii = 0, jj = 0;
            for (int row = 0; row < m.rows; row++) {
                if (row == i) {
                    continue;
                }
                for (int col = 0; col < m.cols; col++) {
                    if (col == j) {
                        continue;
                    }
                    temp.data[ii][jj] = m.data[row][col];
                    jj++;
                    if (jj == m.cols - 1) {
                        ii++;
                        jj = 0;
                    }
                }
            }
            double sign = pow(-1.0, i + j);
            inv.data[j][i] = sign * detMatrix(temp) / det;
        }
    }
    deleteMatrix(temp);
    return inv;
}

matrix traspontMatrix(matrix& m) {
    matrix trans = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            trans.data[j][i] = m.data[i][j];
        }
    }
    return trans;
}

matrix mult_ScalarToMatrix(matrix& m, double scalar) {
    matrix result = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[i][j] = scalar * m.data[i][j];
        }
    }
    return result;
}

matrix subMatrix(matrix& m1, matrix& m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        cout << "������� ������ �� ���������!" << endl;
        return createMatrix(0, 0);
    }
    matrix result = createMatrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return result;
}


matrix multMatrix(matrix& m1, matrix& m2) {
    if (m1.cols != m2.rows) {
        cout << "������������ ������� ������!" << endl;
        return createMatrix(0, 0);
    }
    matrix result = createMatrix(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            for (int k = 0; k < m1.cols; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}


matrix addMatrix(matrix& m1, matrix& m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        cout << "������� ������ �� ���������!" << endl;
        return createMatrix(0, 0);
    }
    matrix result = createMatrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

matrix add_ScalarToMatrix(matrix& m1, int f)
{
    matrix result = createMatrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + f;
        }
    }
    return result;
}
matrix sub_ScalarToMatrix(matrix& m1, int f)
{
    matrix result = createMatrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] - f;
        }
    }
    return result;
}

//void matrixCalc()
//{
//    setlocale(LC_ALL, "rus");
//    int rows, cols;
//    int choice = 0;
//    cout << "������� ���������� ����� � �������� ������: ";
//    cin >> rows >> cols;
//    matrix m1 = createMatrix(rows, cols);
//    matrix m2 = createMatrix(rows, cols);
//    cout << "������� �������� ������ �������:" << endl;
//    inputMatrix(m1);
//    cout << endl << "������ �������:" << endl;
//    outputMatrix(m1);
//    while (true)
//    {
//        cout << "�������� ��������:" << endl;
//        cout << "1. ������� �������" << endl;
//        cout << "2. ������� �������" << endl;
//        cout << "3. �������� �������" << endl;
//        cout << "4. ��������� ������� �� �����" << endl;
//        cout << "5. �������� ������� � ������" << endl;
//        cout << "6. ��������� ����� �� �������" << endl;
//        cout << "7. ���������������� �������" << endl;
//        cout << "8. ���������� �������� �������" << endl;
//        cout << "9. ���������� ������������" << endl;
//        cout << "0. �����" << endl;
//        cout << "������� ����� ��������: ";
//        cin >> choice;
//
//
//        switch (choice) {
//        case 1:
//        {
//            cout << "������� �������� ������ �������:" << endl;
//            inputMatrix(m2);
//            cout << endl << "������ �������:" << endl;
//            outputMatrix(m2);
//            cout << "��������� ��������:" << endl;
//            matrix result = addMatrix(m1, m2);
//            outputMatrix(result);
//            break;
//        }
//        case 2:
//        {
//            cout << "������� �������� ������ �������:" << endl;
//            inputMatrix(m2);
//            cout << endl << "������ �������:" << endl;
//            outputMatrix(m2);
//            cout << "��������� ���������:" << endl;
//            matrix result = subMatrix(m1, m2);
//            outputMatrix(result); break;
//        }
//        case 3:
//        {
//            cout << "������� �������� ������ �������:" << endl;
//            inputMatrix(m2);
//            cout << endl << "������ �������:" << endl;
//            outputMatrix(m2);
//            cout << "��������� ���������:" << endl;
//            matrix result = multMatrix(m1, m2);
//            outputMatrix(result); break;
//        }
//        case 4:
//        {
//            int scal;
//            cout << "������� ����� ��� ��������� ������� �� ����: "; cin >> scal;
//            matrix result = mult_ScalarToMatrix(m1, scal);
//            outputMatrix(result); break;
//        }
//        case 5:
//        {
//            int scal;
//            cout << "������� ����� ��� �������� ������� � ���: "; cin >> scal;
//            matrix result = add_ScalarToMatrix(m1, scal);
//            outputMatrix(result); break;
//        }
//        case 6:
//        {
//            int scal;
//            cout << "������� ����� ��� ��������� ��� �� �������: "; cin >> scal;
//            matrix result = sub_ScalarToMatrix(m1, scal);
//            outputMatrix(result); break;
//        }
//        case 7:
//        {
//            //trans
//            matrix result = traspontMatrix(m1);
//            outputMatrix(result); break;
//        }
//        case 8:
//        {
//            //-1
//            matrix result = inverseMatrix(m1);
//            outputMatrix(result); break;
//        }
//        case 9:
//        {
//            //det
//            double result = detMatrix(m1);
//            cout << "�������: " << endl;
//            outputMatrix(m1);
//            cout << "������������ ������� ����� = " << result << endl; break;
//        }
//        case 0:
//            cout << "��������� ���������" << endl;
//            exit(0);
//        default:
//            cout << "�������� ����. ���������� �����" << endl;
//            break;
//        }
//    }
//    deleteMatrix(m1);
//    deleteMatrix(m2);
//}

void matrixCalc()
{
    setlocale(LC_ALL, "rus");
    int rows, cols;
    int choice = 10;
    do {
        cout << "������� ���������� ����� �������: ";
        cin >> rows;
    } while (!isCorrectInput());
    do {
        cout << "������� ���������� �������� �������: ";
        cin >> cols;
    } while (!isCorrectInput());
    matrix m1 = createMatrix(rows, cols);
    matrix m2 = createMatrix(rows, cols);

    while (choice != 0)
    {
        cout << "�������� ��������:" << endl;
        cout << "1. ������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. �������� �������" << endl;
        cout << "4. ��������� ������� �� �����" << endl;
        cout << "5. �������� ������� � ������" << endl;
        cout << "6. ��������� ����� �� �������" << endl;
        cout << "7. ���������������� �������" << endl;
        cout << "8. ���������� �������� �������" << endl;
        cout << "9. ���������� ������������" << endl;
        cout << "0. �����" << endl;
        cout << "������� ����� ��������: ";
        cin >> choice;


        switch (choice) {
        case 1:
        {
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m1);
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m2);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m2);
            cout << "��������� ��������:" << endl;
            matrix result = addMatrix(m1, m2);
            outputMatrix(result);
            break;
        }
        case 2:
        {

            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m1);
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m2);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m2);
            cout << "��������� ���������:" << endl;
            matrix result = subMatrix(m1, m2);
            outputMatrix(result); break;
        }
        case 3:
        {

            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m1);
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m2);
            } while (!isCorrectInput());
            cout << endl << "������ �������:" << endl;
            outputMatrix(m2);
            cout << "��������� ���������:" << endl;
            matrix result = multMatrix(m1, m2);
            outputMatrix(result); break;
        }
        case 4:
        {
            int scal;


            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            cout << "������� ����� ��� ��������� ������� �� ����: "; cin >> scal;
            matrix result = mult_ScalarToMatrix(m1, scal);
            cout << "���������: " << endl;
            outputMatrix(result); break;
        }
        case 5:
        {
            int scal;

            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            cout << "������� ����� ��� �������� ������� � ���: "; cin >> scal;
            matrix result = add_ScalarToMatrix(m1, scal);
            cout << "���������: " << endl;
            outputMatrix(result); 
        break;
        }
        case 6:
        {
            int scal;

            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            cout << "������� ����� ��� ��������� ��� �� �������: "; cin >> scal;
            matrix result = sub_ScalarToMatrix(m1, scal);
            cout << "���������: " << endl;
            outputMatrix(result); break;
        }
        case 7:
        {
            //trans

            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            matrix result = traspontMatrix(m1);
            cout << "����������������� �������: ";
            outputMatrix(result); break;
        }
        case 8:
        {
            //-1
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            matrix result = inverseMatrix(m1);
            cout << "�������� �������: " << endl;
            outputMatrix(result); break;
        }
        case 9:
        {
            //det
            do {
                cout << "������� �������� ������ �������:" << endl;
                inputMatrix(m1);
            } while (!isCorrectInput());
            cout << endl << "�������:" << endl;
            outputMatrix(m1);
            double result = detMatrix(m1);
            cout << "�������: " << endl;
            outputMatrix(m1);
            cout << "������������ ������� ����� = " << result << endl; break;
        }
        case 0:
            cout << "��������� ���������" << endl;
            break;
        default:
            cout << "�������� ����. ���������� �����" << endl;
            break;
        }
    }
    deleteMatrix(m1);
    deleteMatrix(m2);
}


