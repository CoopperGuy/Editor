#include "stdafx.h"
#include "Terrain.h"
#include "Tile.h"
#include "MFCToolView.h"


CTerrain::CTerrain()
{
}


CTerrain::~CTerrain()
{
	Release_Terrain(); 
}

void CTerrain::Tile_Change(const D3DXVECTOR3 & vMouse, const DWORD & dwDrawID, const DWORD & dwOption /*= 0*/)
{
	int iIndex = GetTileIndex(vMouse); 

	if (-1 == iIndex)
		return; 

	m_vecTile[iIndex]->Set_Id(dwDrawID); 
	m_vecTile[iIndex]->Set_Option(dwOption); 
}

int CTerrain::GetTileIndex(const D3DXVECTOR3 & vPos)
{
	for (int i = 0 ; i < m_vecTile.size(); ++i)
	{
		if (IsPicking(vPos, i))
			return i;
	}
	return -1;
}

bool CTerrain::IsPicking(const D3DXVECTOR3 & vPos, const int & iIndex)
{
	//내적을 이용한 타일 픽킹 
	// 1. 마름모꼴의 꼭지점을 구하자 !!! 
	D3DXVECTOR3 vPoint[4] =
	{
		// 데카르트로 할거라고 
		{ m_vecTile[iIndex]->Get_Pos().x - (TileInfo.TileCX >> 1), m_vecTile[iIndex]->Get_Pos().y + (TileInfo.TileCY * 0.5f), 0.f },
		{ m_vecTile[iIndex]->Get_Pos().x + (TileInfo.TileCX >> 1), m_vecTile[iIndex]->Get_Pos().y + (TileInfo.TileCY * 0.5f), 0.f },
		{ m_vecTile[iIndex]->Get_Pos().x + (TileInfo.TileCX >> 1), m_vecTile[iIndex]->Get_Pos().y - (TileInfo.TileCY * 0.5f), 0.f },
		{ m_vecTile[iIndex]->Get_Pos().x - (TileInfo.TileCX >> 1), m_vecTile[iIndex]->Get_Pos().y - (TileInfo.TileCY * 0.5f), 0.f }

	};
	if (vPoint[0].x < vPos.x && vPoint[1].x > vPos.x) {
		if (vPoint[0].y > vPos.y && vPoint[1].y > vPos.y)
			return true;
	}
	return false;
}

HRESULT CTerrain::Ready_Terrain(TILEINFO _info)
{
	float fX = 0.f, fY = 0.f; 
	CTile* pTile = nullptr; 
	TileInfo = _info;
	m_vecTile.reserve(TileInfo.TileCX * TileInfo.TileCY);
	for (int i = 0 ; i < TileInfo.TileY; ++i)
	{
		for (int j = 0 ;  j < TileInfo.TileX; ++j)
		{
			fX = j * TileInfo.TileCX + (TileInfo.TileCX >> 1);
			fY = i * (TileInfo.TileCY);
			pTile = CTile::Create({ { fX,fY,0.f }, {1.f,1.f,0.f},DWORD(0),DWORD(0) });
			m_vecTile.emplace_back(pTile); 
		}
	}
	return S_OK;
}

void CTerrain::Render_Terrain()
{
	TCHAR szBuf[MAX_PATH]{}; 
	for (int i = 0 ; i < TileInfo.TileCY; ++i)
	{
		for (int j = 0 ; j < TileInfo.TileCX; ++j)
		{
			int iIndex = j + (i * TileInfo.TileCX);
			if (0 > iIndex || m_vecTile.size() <= iIndex)
				return; 
			m_vecTile[iIndex]->Set_View(m_pView);
			m_vecTile[iIndex]->Render_Tile();

		}
	}

}

void CTerrain::Mini_Render_Terrain()
{
	for (int i = 0; i < TileInfo.TileCY; ++i)
	{
		for (int j = 0; j < TileInfo.TileCX; ++j)
		{
			int iIndex = j + (i * TileInfo.TileCX);
			if (0 > iIndex || m_vecTile.size() <= iIndex)
				return;

			m_vecTile[iIndex]->Render_Mini();
		}
	}
}

void CTerrain::Release_Terrain()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), Safe_Delete<CTile*>);
	m_vecTile.clear(); 
	m_vecTile.shrink_to_fit(); 
}

void CTerrain::Delete_Tile()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), Safe_Delete<CTile*>);
	m_vecTile.clear();
}

CTerrain * CTerrain::Create(TILEINFO _info)
{
	CTerrain* pInstance = new CTerrain; 
	if (FAILED(pInstance->Ready_Terrain(_info)))
	{
		Safe_Delete(pInstance); 
		return nullptr;
	}
	return pInstance;
}
