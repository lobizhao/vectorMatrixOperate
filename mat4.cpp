#include <iomanip>
#include <cmath>
#include "mat4.h"

using namespace std;


/// Default Constructor.  Initialize to identity matrix.
mat4::mat4(){
    *this = mat4::identity();
}

//set diag value
mat4::mat4(float diag){

    for(int i=0; i<4; i++){
        for(int j =0; j<4; j++){
            if(i == j){
                data[i][j] = diag;
            }else{
                data[i][j] = 0.0f;
            }
        }
    }

}

//init matrix with each vector representing a column
mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4 &col3){
    data[0] = col0;
    data[1] = col1;
    data[2] = col2;
    data[3] = col3;
}
//copy constructor
mat4::mat4(const mat4 &m2): data(m2.data){ }

// return vector4 which is the index in data
vec4 mat4::operator[](unsigned int index) const{
    if(index >=4){
        throw out_of_range("Index out of range");
    }
    return data[index];
}
//return a reference to column at index
vec4 &mat4::operator[](unsigned int index){
    if(index >=4){
        throw out_of_range("Index out of range");
    }
    return data[index];
}

//too hard, put it at the end
mat4 mat4::rotate(float angle, float x, float y, float z){
    // angle to radian
    float radian = angle *M_PI/ 180.f;
    // normalize axis vector
    float len  = length({x,y,z,0});
    if(len != 0.0f){
        x /= len;
        y /= len;
        z /= len;
    }

    // R = cos(radian)i + sin(radian)k +(1-cos(radian))vvT

    float cosR = cos(radian);
    float sinR = sin(radian);

    vec4 col0 = vec4{
        cosR + x *x *(1.0f- cosR),
        y* x *(1.0f - cosR) + z* sinR,
        z* x *(1.0f-cosR)- y * sinR,
        1.0
    };

    vec4 col1 = vec4{
        x * y * (1.0f- cosR) - z * sinR,
        cosR + y * y * (1.0f- cosR),
        z * y * (1.0f- cosR) + x * sinR,
        0.0f
    };

    vec4 col2 = vec4{
        x * z * (1.0f- cosR) + y * sinR,
        y * z * (1.0f- cosR) - x * sinR,
        cosR + z * z * (1.0f- cosR),
        0.0f
    };

    vec4 col3 = vec4{0.0f,0.0f,0.0f,1.0f};

    return mat4{col0, col1, col2, col3};
}

mat4 mat4::translate(float x, float y, float z){
    //original data[3] ={0,0,0,1};
    // unit vector
    return mat4{
        vec4{1.0f,0.0f,0.0f,0.0f},
        vec4{0.0f,1.0f,0.0f,0.0f},
        vec4{0.0f,0.0f,1.0f,0.0f},
        vec4{x, y, z, 1.0f}
    };
}

mat4 mat4::scale(float x, float y, float z){
    return mat4{
        vec4{x, 0.0f,0.0f,0.0f},
        vec4{0.0f,y,0.0f,0.0f},
        vec4{0.0f,0.0f,z,0.0f},
        vec4{0.0f,0.0f,0.0f,1.0f}
    };
}
/// Generates a 4x4 identity matrix
mat4 mat4::identity(){
    return mat4{1.0f};
}

mat4 &mat4::operator=(const mat4 &m2){
    if(data != m2.data){
        data = m2.data;
    }
    return *this;
}

bool mat4::operator==(const mat4 &m2) const{
    return data == m2.data;
}
bool mat4::operator!=(const mat4 &m2) const{
    return !(data == m2.data);
}

mat4 &mat4::operator+=(const mat4 &m2){
    for(int i=0; i<4; i++){
        data[i] += m2.data[i];
    }
    return *this;
}
mat4 mat4::operator+(const mat4 &m2) const{
    return {
        data[0] + m2.data[0],
        data[1] + m2.data[1],
        data[2] + m2.data[2],
        data[3] + m2.data[3]
    };
}

mat4 &mat4::operator-=(const mat4 &m2){
    for(int i=0; i<4; i++){
        data[i] -= m2.data[i];
    }
    return *this;
}
mat4 mat4::operator-(const mat4 &m2) const{
    return {
        data[0] - m2.data[0],
        data[1] - m2.data[1],
        data[2] - m2.data[2],
        data[3] - m2.data[3]
    };
}

mat4 &mat4::operator*=(float c){
    for(int i=0; i<4; i++){
        data[i] *= c;
    }
    return *this;
}

mat4 mat4::operator*(float c) const{
    return {
        data[0] *c,
        data[1] *c,
        data[2] *c,
        data[3] *c
    };
}

mat4 &mat4::operator/=(float c){
    for(int i=0; i<4; i++){
        data[i] /= c;
    }
    return *this;
}
mat4 mat4::operator/(float c) const{
    return {
        data[0] /c,
        data[1] /c,
        data[2] /c,
        data[3] /c
    };
}

mat4 mat4::operator*(const mat4 &m2) const{
    mat4 ans;

    for(int i =0; i<4; i++){
        for(int j =0; j<4; j++){
            ans[i][j] = 0.0f;
            for(int k =0; k<4; k++){
                ans[i][j] += data[i][k] * m2.data[k][j];
            }
        }
    }
    return ans;
}

vec4 mat4::operator*(const vec4 &v) const{
    vec4 ans{0.0f,0.0f,0.0f,0.0f};
    for(int i =0; i<4; i++){

        for(int j =0; j<4; j++){
            ans[i] += data[j][i]*v[j];
        }
    }
    return ans;
}

// vT operate matrix[i][j] = m[j][i]
mat4 transpose(const mat4 &m){
    mat4 ans;
    for(int i=0; i<4; i++){
        for(int j =0; j<4; j++){
            ans[i][j] = m[j][i];
        }
    }
    return ans;
}

vec4 row(const mat4 &m, unsigned int index){
    if(index >= 4){
        throw out_of_range("index out of range");
    }
    //return m[index];
    return vec4{m[0][index], m[1][index], m[2][index], m[3][index]};
}

mat4 operator*(float c, const mat4 &m){
    mat4 ans;
    for(int i =0; i<4; i++){
        ans[i] = m[i]*c;
    }
    return ans;
}

vec4 operator*(const vec4 &v, const mat4 &m){
    vec4 ans;
    for(int i =0; i <4 ;i++){
        ans[i] = 0.0f;
        for(int j =0; j<4; j++){
            ans[i] += v[j]*m[j][i];
        }
    }
    return ans;
}

std::ostream &operator<<(std::ostream &o, const mat4 &m){
    o << fixed << setprecision(1);
    o<< "{" << m[0][0] <<", "<< m[0][1] << ", "<<m[0][2] <<", "<<m[0][3] <<"\n";
    o<< " " << m[1][0] <<", "<< m[1][1] << ", "<<m[1][2] <<", "<<m[1][3] << "\n";
    o<< " " << m[2][0] <<", "<< m[2][1] << ", "<<m[2][2] <<", "<<m[2][3] << "\n";
    o<< " " << m[3][0] <<", "<< m[3][1] << ", "<<m[3][2] <<", "<<m[3][3] << "}";
    return o;
}
