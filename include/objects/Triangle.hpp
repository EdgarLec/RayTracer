/*
** EPITECH PROJECT, 2023
** Epitech-Raytracer
** File description:
** Triangle
*/

#pragma once

#include "Object.hpp"
#include "render/Ray.hpp"
#include <array>

class Triangle : public AObject {
    public:
        Triangle(Vec3 point1 = Vec3(0, 0, 0), Vec3 point2 = Vec3(1, 0, 0), Vec3 point3 = Vec3(0, 0, 1),
        sf::Color color = sf::Color::Red, sf::Color emmsionColor = sf::Color::Black, float intensity = 1.0f);
        ~Triangle() override = default;
        bool intersect(const Ray &ray, Vec3 &intersection) const override;
        Vec3 getNormal(const Vec3 &inter, const Ray &ray) const override;
        std::array<Vec3, 3> getTmpPoints(const Ray &ray) const;

        // Setters
        template <size_t N>
        void setPoint(const Vec3 &point) {
            _points[N] = point;
        }

    protected:
    private:
        std::array<Vec3, 3> _points;
};
