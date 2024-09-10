// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
    std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;
}
void vectConstructor1Test(){
    vec4 a;
    std::cout << "init new vec4 a expected value : (0.0, 0.0, 0.0, 0.0) "<< std::endl;
    std::cout <<" vec4 a actual value : " << a << std::endl;
}
void vectConstructor2Test(){
    vec4 v1(3.f, 5.f, 1.f, 4.f);
    std::cout << "init new vec4 v1 expected value : (3.0, 5.0, 1.0, 4.0) "<< std::endl;
    std::cout << "test input argv x, y, z, w actual value : " << v1 << std::endl;
}
void vectConstructorCopyTest(){
    vec4 v0(9.f, 9.f, 9.f, 9.f);
    vec4 v2(v0);
    std::cout << "init new vec4 v0 =  v2, so v2 expected value : (9.0, 9.0, 9.0, 9.0) "<< std::endl;
    std::cout<<"text copy constructor v2 actual value : " << v2 << std::endl;
}

void vec4EqualTest(){
    vec4 v0 = {1.0f,2.0f, 3.0f, 4.0f};
    vec4 v1 = v0;
    std::cout << "operate '=' test, set v1 = v0 expected value: (1.0,2.0, 3.0, 4.0)" << std:: endl;
    std::cout << "vec4 v1 value: " << v1 << std::endl;
    std:: cout << std::endl;
}

void vec4DoubleEqual(){
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 a == vec4 b expected value: false(0) "<< std::endl;
    std::cout<<"vec4 a == vec4 b: " <<(a == b)<< std::endl;
    std:: cout << std::endl;

}

void vec4Unequal(){
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 a != vec4 b expected value: true(1) "<< std::endl;
    std::cout<<"vec4 a != vec4 b: " <<(a != b)<< std::endl;
    std:: cout << std::endl;
}

void vec4CrossTest(){
    vec4 v1 = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 v2 = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 a cross vec4 b expected value :  (0.0, 0.0, 0.0, 0.0)" << std::endl;
    std::cout << "vec4 a corss vec4 b value: " << cross(v1, v2) << std::endl;
    std:: cout << std::endl;
}
void vec4PrintTest(){
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    std::cout<< "Print vec4 a:" << a << std::endl;
    std:: cout << std::endl;
}

void vec4DotTest(){
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 a dot vec4 b expected value : 60.0" << std::endl;
    std::cout << "vec4 a dot vec4 b value: " << dot(a, b) << std::endl;
    std:: cout << std::endl;

    vec4 v1(3.f, 5.f, 1.f, 4.f);
    vec4 v0(9.f, 9.f, 9.f, 9.f);
    std::cout << "vec4 v1 dot vec4 v0 expected value : 117.0" << std::endl;
    std::cout << "vec4 v1 dot vec4 v0 value: " << dot(v1, v0) << std::endl;
    std:: cout << std::endl;
}
void vec4NormalizeTest(){
    vec4 a = vec4(5.0f, 5.0f, 5.0f, 5.0f);
    vec4 normalize_a = normalize(a);
    std::cout << "Normalize vec4 a expected value is: (0.5, 0.5, 0.5, 0.5) " << std::endl;
    std::cout << "Normalize vec4 a value: " << normalize_a << std::endl;
    std:: cout << std::endl;
}

// mat4 class test
void mat4constructors1Test(){
    mat4 matrix0;
    std::cout << "new a 4*4 matrix matrix0 excepted value is : matrix0 : \n"
                 "{1.0, 0.0, 0.0, 0.0\n"
                 " 0.0, 1.0, 0.0, 0.0\n"
                 " 0.0, 0.0, 1.0, 0.0\n"
                 " 0.0, 0.0, 0.0, 1.0} "<< std::endl;
    std::cout << " print actual value matrix0 : " << std:: endl << matrix0 <<std::endl;
    std:: cout << std::endl;
}

void mat4constructors2Test(){
    mat4 matrix1(7.0f);
    std::cout << "new a matrix diagonal value is 7.0f excepted value is : matrix1 : \n"
                 "{7.0, 0.0, 0.0, 0.0\n"
                 " 0.0, 7.0, 0.0, 0.0\n"
                 " 0.0, 0.0, 7.0, 0.0\n"
                 " 0.0, 0.0, 0.0, 7.0}" << std::endl;
    std::cout << "print actual value matrix1 : " << std::endl << matrix1 <<std::endl;
    std:: cout << std::endl;
}

void mat4constructors3Test(){
    mat4 matrix2({0.f,1.f,2.f,3.f},{4.f,5.f,6.f,7.f},{8.f,9.f,10.f,11.f},{12.f,13.f,14.f,15.f});
    std::cout << "new a 4*4 matrix with 4 vec4 expect value : matrix with 4 vec4 argv, matrix1 : \n"
                 "{0.0, 1.0, 2.0, 3.0\n"
                 " 4.0, 5.0, 6.0, 7.0\n"
                 " 8.0, 9.0, 10.0, 11.0\n"
                 " 12.0, 13.0, 14.0, 15.0} "<< std::endl;
    std::cout << "matrix with 4 vec4 argv,actual value matrix1 : " << endl << matrix2 << std::endl;
    std:: cout << std::endl;
}
void mat4copyTest(){
    mat4 matrix2({0.f,1.f,2.f,3.f},{4.f,5.f,6.f,7.f},{8.f,9.f,10.f,11.f},{12.f,13.f,14.f,15.f});
    mat4 matrixCopy(matrix2);
    std::cout << "new a 4*4 matrix with 4 vec4 expect value : matrixCopy with 4 vec4 argv, matrix1 : \n"
                 "{0.0, 1.0, 2.0, 3.0\n"
                 " 4.0, 5.0, 6.0, 7.0\n"
                 " 8.0, 9.0, 10.0, 11.0\n"
                 " 12.0, 13.0, 14.0, 15.0} "<< std::endl;
    std::cout << "matrix with 4 vec4 argv,actual value matrixCopy : " << endl << matrix2 << std::endl;
    std:: cout << std::endl;
}

void mat4PrintTest(){
    mat4 matrixPrint(5.0f);
    std::cout<< "mat4 operate << 4*4 matrix expect value is \n {5.0, 0.0, 0.0, 0.0\n"
                 " 0.0, 5.0, 0.0, 0.0\n"
                 " 0.0, 0.0, 5.0, 0.0\n"
                 " 0.0, 0.0, 0.0, 5.0} "<< std::endl;
    std::cout << "matrixPrint << : " << std::endl << matrixPrint << std::endl;
    std:: cout << std::endl;
}

void mat4EqualeTest(){
    mat4 a(3.0f);
    mat4 b = a;
    std::cout <<"mat4 operate = expected b = a expect value is \n{3.0, 0.0, 0.0, 0.0\n"
                 " 0.0, 3.0, 0.0, 0.0\n"
                 " 0.0, 0.0, 3.0, 0.0\n"
                 " 0.0, 0.0, 0.0, 3.0}"<< std::endl;
    std::cout<<"matrix b =  matrix a, actual is matrix b: "<< std::endl << b<<std::endl;
    std:: cout << std::endl;
}

void mat4DoubleTest(){
    mat4 a(3.0f);
    mat4 b(3.0f);
    std::cout<< "a == b, expected value is : ture(1)" << std::endl;
    std::cout << "matrix a == matrix b : "<< (a == b) << std::endl;
    std:: cout << std::endl;
}

void mat4UnequalTest(){
    mat4 a(3.0f);
    mat4 b(3.0f);
    std::cout<< "a != b, expected value is : false(0)" << std::endl;
    std::cout << "matrix a != matrix b : "<< (a != b) << std::endl;
    std:: cout << std::endl;
}

void mat4RotateTest(){
    mat4 a(3.f);

    float angle = 90.f;
    float x = 0.f;
    float y = 0.f;
    float z = 1.f;

    mat4 b = a.rotate(angle, x, y, z);
    std::cout << "rotate matrix along Z axis 90 except value : \n{0.00, 1.00, 0.00, 0.00\n"
                 " -1.00, 0.00, 0.00, 0.00\n"
                 " 0.00, 0.00, 1.00, 0.00\n"
                 " 0.00, 0.00, 0.00, 1.00}" << std::endl;
    std::cout<< "After rotate new matrix is: " << std::endl << b <<std::endl;
    std:: cout << std::endl;

    x = 1.f;
    y = 0.f;
    z = 0.f;
    b = a.rotate(angle, x, y, z);
    std::cout << "rotate matrix along X axis 90 except value :\n {1.00, 0.00, 0.00, 0.00\n"
                 " 0.00, 0.00, 1.00, 0.00\n"
                 " 0.00, -1.00, 0.00, 0.00\n"
                 " 0.00, 0.00, 0.00, 1.00}" << std::endl;
    std::cout<< "After rotate new matrix is: " << std::endl << b <<std::endl;
    std:: cout << std::endl;
}

void mat4MultiMat4Test(){
    mat4 a{3.f};
    mat4 b{2.f};
    mat4 c = a*b;
    std::cout << "matrix c = a *b  except value :\n {6.00, 0.00, 0.00, 0.00\n"
                 " 0.00, 6.00, 0.00, 0.00\n"
                 " 0.00, 0.00, 6.00, 0.00\n"
                 " 0.00, 0.00, 0.00, 6.00}" << std::endl;
    std::cout << "actual value  matrix a * matirx b : "<<std::endl << c<<std::endl;
    std:: cout << std::endl;
}
void mat4Vec4MultiTest(){
    mat4 m({0.f,1.f,2.f,3.f},{4.f,5.f,6.f,7.f},{8.f,9.f,10.f,11.f},{12.f,13.f,14.f,15.f});
    vec4 v{1.f,2.f,3.f,4.f};

    std::cout<< "mat4 *vector m*v expected value is : (80.0, 90.0, 100.0, 110.0) "<< std::endl;
    std::cout<< "mat4 m * vec4 v : "<< std::endl << m*v<< std::endl;
    std:: cout << std::endl;
}

void vec4Mat4MultiTest(){
    mat4 m({0.f,1.f,2.f,3.f},{4.f,5.f,6.f,7.f},{8.f,9.f,10.f,11.f},{12.f,13.f,14.f,15.f});
    vec4 v{1.f,2.f,3.f,4.f};
    std::cout<< "vec4 * matrix v*m expected value is : (80.0, 90.0, 100.0, 110.0) "<< std::endl;
    std::cout<< "vec4 v * mat4 m : "<< std::endl << v*m << std::endl;
    std:: cout << std::endl;

}



int main() {

    // Example test (won't work until you implement vec4's operator+ and operator<<)
    vec4AddTest();

    //test vec4 constructors
    vectConstructor1Test();
    vectConstructor2Test();
    vectConstructorCopyTest();

    //test operate <<
    vec4PrintTest();
    //test operate =
    vec4EqualTest();
    //test operate ==
    vec4DoubleEqual();
    //test unequal !=
    vec4Unequal();
    //test cross product
    vec4CrossTest();
    //test dot product
    vec4DotTest();
    //test normalized
    vec4NormalizeTest();


    //test  mat4 constructors
    mat4constructors1Test();
    mat4constructors2Test();
    mat4constructors3Test();
    mat4copyTest();

    //mat4 operate << test
    mat4PrintTest();
    //mat4 operate = test
    mat4EqualeTest();
    //mat4 operate == test
    mat4DoubleTest();
    //mat4 operate != test
    mat4UnequalTest();

    //mat4 rotate test 2 case Z axis and X axis
    mat4RotateTest();
    //mat4 matrix - matrix Multiplication
    mat4MultiMat4Test();
    //vec4 matrix -vector Multiplication
    mat4Vec4MultiTest();
    //vec4 vector - matrix Multiplication
    vec4Mat4MultiTest();

}
