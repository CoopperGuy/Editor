#include "stdafx.h"
#include "Room.h"
#include "Terrain.h"
#include "MFCToolView.h"

CRoom::CRoom():Terrain(nullptr)
{
	ZeroMemory(&TileInfo, sizeof(TILEINFO));
	//������Ʈ�� �ְ� �̰����� �����ÿ�.
	//������ terrain �� create�ϰ� �س�����
	//���߿��� ��� ������ �ε常 �ؼ� ������ ���̴�.
	//save load �����ʿ�

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

