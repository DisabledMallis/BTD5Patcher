#ifndef PATCHER_CLASSES_VECTOR
#define PATCHER_CLASSES_VECTOR

namespace Patcher
{
    namespace Classes
    {
		template<typename T>
		struct Vector1
		{
			T x = 0;
			Vector1() = default;
			Vector1(T x) : x(x) { }
			Vector1<T> operator+(Vector1<T>& other) const { return Vector1<T>(this->x + other.x); }
			Vector1<T> operator-(Vector1<T>& other) const { return Vector1<T>(this->x - other.x); }
			Vector1<T> operator*(Vector1<T>& other) const { return Vector1<T>(this->x * other.x); }
			Vector1<T> operator/(Vector1<T>& other) const { return Vector1<T>(this->x / other.x); }
			Vector1<T>& operator+=(Vector1<T>& other) { this->x += other.x; return *this; }
			Vector1<T>& operator-=(Vector1<T>& other) { this->x -= other.x; return *this; }
			Vector1<T>& operator*=(Vector1<T>& other) { this->x *= other.x; return *this; }
			Vector1<T>& operator/=(Vector1<T>& other) { this->x /= other.x; return *this; }
			Vector1<T> operator+(T other) const { return Vector1<T>(this->x + other); }
			Vector1<T> operator-(T other) const { return Vector1<T>(this->x - other); }
			Vector1<T> operator*(T other) const { return Vector1<T>(this->x * other); }
			Vector1<T> operator/(T other) const { return Vector1<T>(this->x / other); }
			Vector1<T>& operator+=(T other) { this->x += other; return *this; }
			Vector1<T>& operator-=(T other) { this->x -= other; return *this; }
			Vector1<T>& operator*=(T other) { this->x *= other; return *this; }
			Vector1<T>& operator/=(T other) { this->x /= other; return *this; }
			T& operator[](int index) { *(this + (index * sizeof(T))); }
		};

		template<typename T>
		struct Vector2 : public Vector1<T>
		{
			T y = 0;
			Vector2() = default;
			Vector2(T x, T y) : Vector1<T>(x), y(y) { }
			Vector2<T> operator+(Vector2<T>& other) const { return Vector2<T>(this->x + other.x, this->y + other.y); }
			Vector2<T> operator-(Vector2<T>& other) const { return Vector2<T>(this->x - other.x, this->y - other.y); }
			Vector2<T> operator*(Vector2<T>& other) const { return Vector2<T>(this->x * other.x, this->y * other.y); }
			Vector2<T> operator/(Vector2<T>& other) const { return Vector2<T>(this->x / other.x, this->y / other.y); }
			Vector2<T>& operator+=(Vector2<T>& other) { this->x += other.x; this->y += other.y; return *this; }
			Vector2<T>& operator-=(Vector2<T>& other) { this->x -= other.x; this->y -= other.y; return *this; }
			Vector2<T>& operator*=(Vector2<T>& other) { this->x *= other.x; this->y *= other.y; return *this; }
			Vector2<T>& operator/=(Vector2<T>& other) { this->x /= other.x; this->y /= other.y; return *this; }
			Vector2<T> operator+(T other) const { return Vector2<T>(this->x + other, this->y + other); }
			Vector2<T> operator-(T other) const { return Vector2<T>(this->x - other, this->y - other); }
			Vector2<T> operator*(T other) const { return Vector2<T>(this->x * other, this->y * other); }
			Vector2<T> operator/(T other) const { return Vector2<T>(this->x / other, this->y / other); }
			Vector2<T>& operator+=(T other) { this->x += other; this->y += other; return *this; }
			Vector2<T>& operator-=(T other) { this->x -= other; this->y -= other; return *this; }
			Vector2<T>& operator*=(T other) { this->x *= other; this->y *= other; return *this; }
			Vector2<T>& operator/=(T other) { this->x /= other; this->y /= other; return *this; }
			T& operator[](int index) { *(this + (index * sizeof(T))); }
		};

		template<typename T>
		struct Vector3 : public Vector2<T>
		{
			T z = 0;
			Vector3() = default;
			Vector3(T x, T y, T z) : Vector2<T>(x, y), z(z) { }
			Vector3<T> operator+(Vector3<T>& other) const { return Vector3<T>(this->x + other.x, this->y + other.y, this->z + other.z); }
			Vector3<T> operator-(Vector3<T>& other) const { return Vector3<T>(this->x - other.x, this->y - other.y, this->z - other.z); }
			Vector3<T> operator*(Vector3<T>& other) const { return Vector3<T>(this->x * other.x, this->y * other.y, this->z * other.z); }
			Vector3<T> operator/(Vector3<T>& other) const { return Vector3<T>(this->x / other.x, this->y / other.y, this->z / other.z); }
			Vector3<T>& operator+=(Vector3<T>& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
			Vector3<T>& operator-=(Vector3<T>& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }
			Vector3<T>& operator*=(Vector3<T>& other) { this->x *= other.x; this->y *= other.y; this->z *= other.z; return *this; }
			Vector3<T>& operator/=(Vector3<T>& other) { this->x /= other.x; this->y /= other.y; this->z /= other.z; return *this; }
			Vector3<T> operator+(T other) const { return Vector3<T>(this->x + other, this->y + other, this->z + other); }
			Vector3<T> operator-(T other) const { return Vector3<T>(this->x - other, this->y - other, this->z - other); }
			Vector3<T> operator*(T other) const { return Vector3<T>(this->x * other, this->y * other, this->z * other); }
			Vector3<T> operator/(T other) const { return Vector3<T>(this->x / other, this->y / other, this->z / other); }
			Vector3<T>& operator+=(T other) { this->x += other; this->y += other; this->z += other; return *this; }
			Vector3<T>& operator-=(T other) { this->x -= other; this->y -= other; this->z -= other; return *this; }
			Vector3<T>& operator*=(T other) { this->x *= other; this->y *= other; this->z *= other; return *this; }
			Vector3<T>& operator/=(T other) { this->x /= other; this->y /= other; this->z /= other; return *this; }
			T& operator[](int index) { *(this + (index * sizeof(T))); }
		};
	} //namespace Classes
} //namespace Patcher

#endif /* PATCHER_CLASSES_VECTOR */
