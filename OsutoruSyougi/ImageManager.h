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
	// std::map<���̌^,�A�z�z��̌^> �A�z�z��;
	std::map<std::string, VEC_INT> imageMap;	// �Ұ��map	�ϒ��œǂݍ���file�ɂ���đ傫�����ς��
};

