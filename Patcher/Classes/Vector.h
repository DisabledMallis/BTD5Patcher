#ifndef PATCHER_CLASSES_VECTOR
#define PATCHER_CLASSES_VECTOR

namespace Patcher
{
    namespace Classes
    {
		template<class T>
		class Vector1 {
			T x;
		public:
			Vector1<T>() {
				this->x = 0;
			};
			Vector1<T>(T x) {
				this->x = x;
			};

			auto getX() -> T {
				return this->x;
			};
			void setX(T x) {
				this->x = x;
			};

			Vector1 operator+(Vector1 other) {
				return Vector1(this->x + other->x);
			};
			Vector1 operator-(Vector1 other) {
				return Vector1(this->x - other->x);
			};
			Vector1 operator*(Vector1 other) {
				return Vector1(this->x * other->x);
			};
			Vector1 operator/(Vector1 other) {
				return Vector1(this->x / other->x);
			};
		};

		template<class T>
		class Vector2 : public Vector1<T> {
			T y;
		public:
			Vector2<T>() : Vector1<T>(0) {
				this->y = 0;
			};
			Vector2<T>(T x, T y) : Vector1<T>(x) {
				this->y = y;
			};

			auto getY() -> T {
				return this->y;
			};
			void setY(T y) {
				this->y = y;
			};
			Vector2 operator+(Vector2 other) {
				return Vector2(
					this->x + other->x,
					this->y + other->y
				);
			};
			Vector2 operator-(Vector2 other) {
				return Vector2(
					this->x - other->x,
					this->y - other->y
				);
			};
			Vector2 operator*(Vector2 other) {
				return Vector2(
					this->x * other->x,
					this->y * other->y
				);
			};
			Vector2 operator/(Vector2 other) {
				return Vector2(
					this->x / other->x,
					this->y / other->y
				);
			};
		};

		template<class T>
		class Vector3 : public Vector2<T> {
			T z;
		public:
			Vector3<T>() : Vector2<T>(0, 0) {
				this->z = 0;
			};
			Vector3<T>(T x, T y, T z) : Vector2<T>(x, y) {
				this->z = z;
			};

			auto getZ() -> T {
				return this->z;
			};
			void setZ(T z) {
				this->z = z;
			};
			Vector3 operator+(Vector3 other) {
				return Vector3(
					this->x + other->x,
					this->y + other->y,
					this->z + other->z
				);
			};
			Vector3 operator-(Vector3 other) {
				return Vector3(
					this->x - other->x,
					this->y - other->y,
					this->z - other->z
				);
			};
			Vector3 operator*(Vector3 other) {
				return Vector3(
					this->x * other->x,
					this->y * other->y,
					this->z * other->z
				);
			};
			Vector3 operator/(Vector3 other) {
				return Vector3(
					this->x / other->x,
					this->y / other->y,
					this->z / other->z
				);
			};
		};
	} //namespace Classes
} //namespace Patcher

#endif /* PATCHER_CLASSES_VECTOR */
