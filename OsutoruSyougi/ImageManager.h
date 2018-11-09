#pragma once
#include <map>
#include <vector>
#include <mutex>
#include "VECTOR2.h"

using  VEC_INT = std::vector<int>;
#define IMAGE_ID(X)	(ImageManager::GetInstance().GetID(X))

class ImageManager
{
public:
	static ImageManager &GetInstance()
	{
		return *s_Instance;
	}
	const VEC_INT &GetID(std::string f_name);
	const VEC_INT &GetID(std::string f_name, VECTOR2 divSize, VECTOR2 divCnt, VECTOR2 chipOffset);
private:
	ImageManager();
	~ImageManager();
	
	struct ImageManagerDeleter
	{
		void operator()(ImageManager* imagerManager) const
		{
			delete imagerManager;
		}
	};

	static std::unique_ptr<ImageManager, ImageManagerDeleter> s_Instance;
	// std::map<ｷｰの型,連想配列の型> 連想配列名;
	std::map<std::string, VEC_INT> imageMap;	// ｲﾒｰｼﾞmap	可変長で読み込むfileによって大きさが変わる
};

