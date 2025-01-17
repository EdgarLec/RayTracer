/*
** EPITECH PROJECT, 2023
** Epitech-Raytracer
** File description:
** maths
*/

#pragma once

#include "render/Sfml.hpp"
#include "Matrix.hpp"
#include <random>
#include <cmath>
#define POW4(x) ((x) * (x) * (x) * (x))
#define POW3(x) ((x) * (x) * (x))
#define POW2(x) ((x) * (x))

namespace Math
{
    Vec3 normalize(const Vec3 &vec);
    float dot(const Vec3 &vec1, const Vec3 &vec2);
    float randomf(float min, float max);
    float realRandomf(float min, float max);
    int random(int min, int max);
    bool isPowerOfTwo(int n);
    float toDeg(float rad);
    float toRad(float deg);

    // Solvers
    std::vector<float> solveLinear(const float coeffs[2]);
    std::vector<float> solveQuadratic(const float coeffs[3]);
    std::vector<float> solveCubic(const float coeffs[4]);
    std::vector<float> solveQuartic(const float coeffs[5]);

    Vec3 randomDir(const Vec3 &normal);
    float sign(float val);
    Vec3 cross(const Vec3 &vec1, const Vec3 &vec2);
    Vec3 lerp(const Vec3 &vec1, const Vec3 &vec2, float t);
    float length(const Vec3 &vec);
    bool sameSign(const Vec3 &a, const Vec3 &b);
    Vec3 proj(const Vec3 &vec1, const Vec3 &vec2);
    Vec3 refract(const Vec3 &incident, const Vec3 &normal, float n1, float n2);
    float fresnel(float cosi, float etai, float etat);
}
