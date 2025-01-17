/*
** EPITECH PROJECT, 2023
** Epitech-Raytracer
** File description:
** LightPoint
*/

#pragma once

#include "render/Sfml.hpp"
#include "ILight.hpp"

class LightPoint : public ALight {
    public:
        LightPoint(Vec3 pos = VEC3_ZERO, Vec3 color = WHITE, float intensity = 1.0f);
        ~LightPoint() = default;

        Vec3 getPos() const {return _pos;};
        void setPos(const Vec3 &pos) {_pos = pos;};
        Vec3 illuminate(const Vec3 &normal, const Vec3 &inter, const Vec3 &color, const Scene &pool, const IObject *obj) const;
    private:
        Vec3 _pos;
};
