#pragma once
#include <voxel/array3.hpp>
#include <voxel/registry.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster;

	class Sector
	{
	protected:
		sector_pos_t position;
		Array3<id_t> ids;
		Array3<md_t> mds;
	public:
		Sector(const sector_pos_t& _position,
			const Array3<id_t>& _ids,
			const Array3<md_t>& _mds) :
			position(_position),
			ids(_ids),
			mds(_mds)
		{}
		Sector(const sector_pos_t& _position,
			const Vec3<size_t> size = Vec3<size_t>(
			sectorLength, sectorLength, sectorLength),
			const id_t id = nullVoxelID,
			const md_t md = nullVoxelMD) :
			position(_position),
			ids(size, id),
			mds(size, md)
		{}
		virtual ~Sector()
		{}

		inline const sector_pos_t& getPosition() const noexcept
		{
			return position;
		}

		inline Array3<id_t>& getIDS() noexcept
		{
			return ids;
		}
		inline const Array3<id_t>& getIDS() const noexcept
		{
			return ids;
		}

		inline Array3<md_t>& getMDS() noexcept
		{
			return mds;
		}
		inline const Array3<md_t>& getMDS() const noexcept
		{
			return mds;
		}

		virtual void update(
			const Registry& registry,
			const Cluster& cluster,
			const time_t deltaTime)
		{
			for (size_t i = 0; i < sectorSize; i++)
			{
				const auto id = ids.get(i);
				const auto& voxel = registry.get(id);

				if (voxel.updater)
					voxel.updater->update(
						registry, cluster, deltaTime, i);
			}
		}
	};
}
