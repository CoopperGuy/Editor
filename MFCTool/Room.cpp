#include "stdafx.h"
#include "Room.h"
#include "Terrain.h"
#include "MFCToolView.h"

CRoom::CRoom():Terrain(nullptr)
{
	ZeroMemory(&TileInfo, sizeof(TILEINFO));
	//오브젝트도 넣고 이것저것 넣으시오.
	//지금은 terrain 을 create하게 해놨지만
	//나중에는 모든 정보를 로드만 해서 가져올 것이다.
	//save load 구현필요

}


CRoom::~CRoom()
{
	Release_Room();
}

HRESULT CRoom::Ready_Room(TILEINFO _info)
{
	Terrain = CTerrain::Create(_info);
	return S_OK;
}

void CRoom::Render_Room()
{
	Terrain->Set_View(m_pView);
	Terrain->Render_Terrain();
}

void CRoom::Mini_Render_Room()
{
	Terrain->Mini_Render_Terrain();
}

void CRoom::Release_Room()
{
	Safe_Delete(Terrain);
}

void CRoom::Change_Tile(const D3DXVECTOR3 & vMouse, const DWORD & dwDrawID, const DWORD & dwOption)
{
	Terrain->Tile_Change(vMouse, dwDrawID);
}

CRoom * CRoom::Create(TILEINFO _info)
{
	CRoom* pInstance = new CRoom;
	if (FAILED(pInstance->Ready_Room(_info)))
	{
		Safe_Delete(pInstance);
		return nullptr;
	}
	return pInstance;
}

