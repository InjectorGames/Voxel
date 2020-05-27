#pragma once
#include <voxel/defines.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	template<class T>
	class Array3
	{
	protected:
		size_t count;
		size3_t size;
		T* data;
	public:
		Array3(const size3_t& _size,
			const T& value = T()) :
			count(_size.x * _size.y * _size.z),
			size(_size)
		{
			data = new T[count];
			std::uninitialized_fill_n(data, count, value);
		}
		Array3(const Array3<T>& array) :
			count(array.count),
			size(array.size)
		{
			data = new T[count];
			std::uninitialized_copy_n(array.data, count, data);
		}
		virtual ~Array3()
		{
			delete[] data;
			data = nullptr;
		}

		inline const size_t getCount() const noexcept
		{
			return count;
		}

		inline const size3_t& getSize() const noexcept
		{
			return size;
		}

		inline T* getData() noexcept
		{
			return data;
		}
		inline const T* getData() const noexcept
		{
			return data;
		}

		inline T& get(
			const size_t index) noexcept
		{
			return data[index];
		}
		inline const T& get(
			const size_t index) const noexcept
		{
			return data[index];
		}
		inline T& get(
			const size3_t& position) noexcept
		{
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline T& get(
			const size_t x, const size_t y, const size_t z) noexcept
		{
			return data[x + size.x * (y + size.y * z)];
		}
		inline const T& get(
			const size3_t& position) const noexcept
		{
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline const T& get(
			const size_t x, const size_t y, const size_t z) const noexcept
		{
			return data[x + size.x * (y + size.y * z)];
		}

		inline void set(
			const size_t index, const T& value) noexcept
		{
			data[index] = T(value);
		}
		inline void set(
			const size3_t& position, const T& value) noexcept
		{
			data[position.x + size.x * (position.y + size.y * position.z)] = T(value);
		}
		inline void set(
			const size_t x, const size_t y, const size_t z, const T& value) noexcept
		{
			data[x + size.x * (y + size.y * z)] = T(value);
		}

		inline T& getSafe(
			const size_t index)
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline const T& getSafe(
			const size_t index) const
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline T& getSafe(
			const size3_t& position)
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline T& getSafe(
			const size_t x, const size_t y, const size_t z)
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * (y + size.y * z)];
		}
		inline const T& getSafe(
			const size3_t& position) const
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline const T& getSafe(
			const size_t x, const size_t y, const size_t z) const
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * (y + size.y * z)];
		}

		inline void setSafe(
			const size_t index, const T& value)
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			data[index] = T(value);
		}
		inline void setSafe(
			const size3_t& position, const T& value)
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			data[position.x + size.x * (position.y + size.y * position.z)] = T(value);
		}
		inline void setSafe(
			const size_t x, const size_t y, const size_t z, const T& value)
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			data[x + size.x * (y + size.y * z)] = T(value);
		}

		inline T& getNoex(
			const size_t index, T& value) noexcept
		{
			if (index >= count)
				return false;
			value = data[index];
			return true;
		}
		inline const T& getNoex(
			const size_t index, const T& value) const noexcept
		{
			if (index >= count)
				return false;
			value = data[index];
			return true;
		}
		inline T& getNoex(
			const size3_t& position, T& value) noexcept
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				return false;
			value = data[position.x + size.x * (position.y + size.y * position.z)];
			return true;
		}
		inline T& getNoex(
			const size_t x, const size_t y, const size_t z, T& value) noexcept
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				return false;
			value = data[x + size.x * (y + size.y * z)];
			return true;
		}
		inline const T& getNoex(
			const size3_t& position, const T& value) const noexcept
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				return false;
			value = data[position.x + size.x * (position.y + size.y * position.z)];
			return true;
		}
		inline const T& getNoex(
			const size_t x, const size_t y, const size_t z, const T& value) const noexcept
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				return false;
			value = data[x + size.x * (y + size.y * z)];
			return true;
		}

		inline const bool setNoex(
			const size_t index, const T& value) noexcept
		{
			if (index >= count)
				return false;
			data[index] = T(value);
			return true;
		}
		inline const bool setNoex(
			const size3_t& position, const T& value) noexcept
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				return false;
			data[position.x + size.x * (position.y + size.y * position.z)] = T(value);
			return true;
		}
		inline const bool setNoex(
			const size_t x, const size_t y, const size_t z, const T& value) noexcept
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				return false;
			data[x + size.x * (y + size.y * z)] = T(value);
			return true;
		}

		inline void fill(const T& value = T()) noexcept
		{
			std::uninitialized_fill_n(data, size, value);
		}
	};

	inline static const size_t positionToIndex(
		const size3_t& size, const size3_t& position) noexcept
	{
		return static_cast<size_t>(position.x + size.x * (position.y + size.y * position.z));
	}
	inline static const size_t positionToIndex(
		const size3_t& size, const size_t x, const size_t y, const size_t z) noexcept
	{
		return static_cast<size_t>(x + size.x * (y + size.y * z));
	}
	template<size_t SX, size_t SY>
	inline static const size_t positionToIndex(
		const size3_t& position) noexcept
	{
		return static_cast<size_t>(position.x + SX * (position.y + SY * position.z));
	}
	template<size_t SX, size_t SY>
	inline static const size_t positionToIndex(
		const size_t x, const size_t y, const size_t z) noexcept
	{
		return static_cast<size_t>(x + SX * (y + SY * z));
	}
	inline static const size_t positionToIndexSafe(
		const size3_t& size, const size3_t& position)
	{
		if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
			throw std::out_of_range("Out of size range");
		return static_cast<size_t>(position.x + size.x * (position.y + size.y * position.z));
	}
	inline static const size_t positionToIndexSafe(
		const size3_t& size, const size_t x, const size_t y, const size_t z)
	{
		if (x >= size.x || y >= size.y || z >= size.z)
			throw std::out_of_range("Out of size range");
		return static_cast<size_t>(x + size.x * (y + size.y * z));
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const size_t positionToIndexSafe(
		const size3_t& position)
	{
		if (position.x >= SX || position.y >= SY || position.z >= SZ)
			throw std::out_of_range("Out of size range");
		return static_cast<size_t>(position.x + SX * (position.y + SY * position.z));
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const size_t positionToIndexSafe(
		const size_t x, const size_t y, const size_t z)
	{
		if (x >= SX || y >= SY || z >= SZ)
			throw std::out_of_range("Out of size range");
		return static_cast<size_t>(x + SX * (y + SY * z));
	}
	inline static const bool positionToIndexNoex(
		const size3_t& size, const size3_t& position, size_t& index) noexcept
	{
		if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
			return false;
		index = static_cast<size_t>(position.x + size.x * (position.y + size.y * position.z));
		return true;
	}
	inline static const bool positionToIndexNoex(
		const size3_t& size, const size_t x, const size_t y, const size_t z, size_t& index) noexcept
	{
		if (x >= size.x || y >= size.y || z >= size.z)
			return false;
		index = static_cast<size_t>(x + size.x * (y + size.y * z));
		return true;
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const bool positionToIndexNoex(
		const size3_t& position, size_t& index) noexcept
	{
		if (position.x >= SX || position.y >= SY || position.z >= SZ)
			return false;
		index = static_cast<size_t>(position.x + SX * (position.y + SY * position.z));
		return true;
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const bool positionToIndexNoex(
		const size_t x, const size_t y, const size_t z, size_t& index) noexcept
	{
		if (x >= SX || y >= SY || z >= SZ)
			return false;
		index = static_cast<size_t>(x + SX * (y + SY * z));
		return true;
	}

	inline static const size3_t indexToPosition(
		size_t index, const size3_t& size) noexcept
	{
		size3_t position;
		position.z = static_cast<size_val_t>(index / (size.x * size.y));
		index -= static_cast<size_t>(position.z * (size.x * size.y));
		position.y = static_cast<size_val_t>(index / size.x);
		position.x = static_cast<size_val_t>(index - position.y * size.x);
		return position;
	}
	template<size_t SX, size_t SY>
	inline static const size3_t indexToPosition(
		size_t index) noexcept
	{
		size3_t position;
		position.z = static_cast<size_val_t>(index / (SX * SY));
		index -= position.z * (SX * SY);
		position.y = static_cast<size_val_t>(index / SX);
		position.x = static_cast<size_val_t>(index - position.y * SX);
		return position;
	}
	inline static const size3_t indexToPositionSafe(
		size_t index, const size3_t& size)
	{
		if (index >= size.x * size.y * size.z)
			throw std::out_of_range("Out of size range");
		size3_t position;
		position.z = static_cast<size_val_t>(index / (size.x * size.y));
		index -= position.z * (size.x * size.y);
		position.y = static_cast<size_val_t>(index / size.x);
		position.x = static_cast<size_val_t>(index - position.y * size.x);
		return position;
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const size3_t indexToPositionSafe(
		size_t index)
	{
		if (index >= SX * SY * SZ)
			throw std::out_of_range("Out of size range");
		size3_t position;
		position.z = static_cast<size_val_t>(index / (SX * SY));
		index -= position.z * (SX * SY);
		position.y = static_cast<size_val_t>(index / SX);
		position.x = static_cast<size_val_t>(index - position.y * SX);
		return position;
	}
	inline static const bool indexToPositionNoex(
		size_t index, const size3_t& size, size3_t& position) noexcept
	{
		if (index >= size.x * size.y * size.z)
			return false;
		position.z = static_cast<size_val_t>(index / (size.x * size.y));
		index -= position.z * (size.x * size.y);
		position.y = static_cast<size_val_t>(index / size.x);
		position.x = static_cast<size_val_t>(index - position.y * size.x);
		return true;
	}
	template<size_t SX, size_t SY, size_t SZ>
	inline static const bool indexToPositionNoex(
		size_t index, const size3_t& size, size3_t& position) noexcept
	{
		if (index >= SX * SY * SZ)
			return false;
		position.z = static_cast<size_val_t>(index / (SX * SY));
		index -= position.z * (SX * SY);
		position.y = static_cast<size_val_t>(index / SX);
		position.x = static_cast<size_val_t>(index - position.y * SX);
		return true;
	}
}
