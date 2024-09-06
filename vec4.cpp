#include <valarray>
#include <iomanip>
#include "vec4.h"

using namespace std;

//init vec4 as 0.0f
vec4::vec4() :data{0.0f, 0.0f, 0.0f, 0.0f}{

}
//set data x, y ,z ,w
vec4::vec4(float x, float y, float z, float w):data{x, y, z, w}{

}

vec4::vec4(const vec4 &v2) :data{v2.data} {

}
// return the value or throw error
float vec4::operator[](unsigned int index)const{
    if(index >=4 || index <0){
        throw out_of_range("Index out of range");
    }
    return data[index];
}

//set data[index]
float &vec4::operator[](unsigned int index){
    if(index >=4 || index <0){
        throw out_of_range("Index out of range");
    }
    return data[index];

}

vec4 &vec4::operator=(const vec4 &v2){
    //    data = v2.data;
    if(data != v2.data){
        data = v2.data;
    }
    return *this;
}

bool vec4::operator==(const vec4 &v2) const{
    return data == v2.data;
}

bool vec4::operator!=(const vec4 &v2) const{
    return !(*this == v2);
}

vec4 vec4::operator+(const vec4 &v2)const{
    return vec4{data[0] + v2.data[0], data[1]+v2.data[1], data[2]+v2.data[2], data[3]+v2.data[3]};
}

vec4 &vec4::operator+=(const vec4 &v2){
    data[0] += v2.data[0];
    data[1] += v2.data[1];
    data[2] += v2.data[2];
    data[3] += v2.data[3];
    return *this;
}

vec4 vec4::operator-(const vec4 &v2)const{
    // vec4 res = (data[0]-v2.data[0], data[1]-v2.data[1], data[2]-v2.data[2], data[3]-v2.data[3]);
    return vec4(data[0]-v2.data[0], data[1]-v2.data[1], data[2]-v2.data[2], data[3]-v2.data[3]);
}

vec4 &vec4::operator-=(const vec4 &v2){
    data[0] -= v2.data[0];
    data[1] -= v2.data[1];
    data[2] -= v2.data[2];
    data[3] -= v2.data[3];
    return *this;
}
vec4 vec4::operator*(float c)const{
    return vec4{data[0]*c, data[1]*c, data[2]*c, data[3]*c};
}
vec4 &vec4::operator*=(float c){
    data[0] *= c;
    data[1] *= c;
    data[2] *= c;
    data[3] *= c;
    return *this;
}
vec4 vec4::operator/(float c)const{
    return vec4{data[0]/c, data[1]/c, data[2]/c ,data[3]/c};
}
vec4 &vec4::operator/=(float c){
    data[0] /= c;
    data[1] /= c;
    data[2] /= c;
    data[3] /= c;
    return *this;
}

/// Dot Product
float dot(const vec4 &v1, const vec4 &v2){
    float ans = v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2] + v1[3]*v2[3];
    return ans;
}

/// Cross Product
vec4 cross(const vec4 &v1, const vec4 &v2){
    vec4 ans;
    ans[0] = v1[1]*v2[2] - v1[2]*v2[1];
    ans[1] = v1[2]*v2[0] - v1[0]*v2[2];
    ans[2] = v1[0]*v2[1] - v1[1]*v2[0];
    ans[3] = 0.0;
    return ans;
}
// vector magnitude
float length(const vec4 &v){
    float magnitude = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3]);
    return magnitude;
}

/// Scalar Multiplication (c * v)
vec4 operator*(float c, const vec4 &v){
    return {c*v[0], c*v[1], c*v[2], c*v[3]};
}

vec4 normalize(const vec4 &v){
    float magnitude = length(v);
    return {v[0]/magnitude, v[1]/magnitude, v[2]/magnitude, v[3]/magnitude};
}
/// Prints the vector to a stream in a nice format
std::ostream &operator<<(std::ostream &o, const vec4 &v){
    //o<<"{" << v[0] + 0.0f <<", " << v[1] + 0.0f << ", " << v[2] + 0.0f << ", " << v[3] + 0.0f << "}";
    o << fixed << setprecision(1); //set float, ok fine
    o<<"(" <<v[0]<<", " << v[1] << ", " << v[2] << ", " << v[3] << ")" ;
    return o;
}
