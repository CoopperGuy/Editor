#include "stdafx.h"
#include "Tile.h"
#include "MFCToolView.h"

CTile::CTile()
{
	ZeroMemory(&TileInfo, sizeof(TILE));
	ZeroMemory(m_vP, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(m_vQ, sizeof(D3DXVECTOR3) * 4);
}


CTile::~CTile()
{
	Release_Tile();
}

HRESULT CTile::Ready_Tile(TILE _tile)
{
	m_vP[0] = { -TileInfo.vSize.x * 0.5f, -TileInfo.vSize.y * 0.5f, 0.f };
	m_vP[1] = { TileInfo.vSize.x * 0.5f, -TileInfo.vSize.y * 0.5f, 0.f };
	m_vP[2] = { TileInfo.vSize.x * 0.5f, TileInfo.vSize.y * 0.5f, 0.f };
	m_vP[3] = { -TileInfo.vSize.x * 0.5f, TileInfo.vSize.y * 0.5f, 0.f };

	D3DXMATRIX matScale , matTrans,  matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);
	D3DXMatrixTranslation(&matTrans, TileInfo.vPos.x, TileInfo.vPos.y, 0.f);

	matWorld = matScale  * matTrans ;

	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&m_vQ[i], &m_vP[i], &matWorld);
	}
	TileInfo = _tile;
	return S_OK;
}

void CTile::Render_Tile()
{
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Terrain", L"Tile", TileInfo.dwDrawID);
	if (nullptr == pTexInfo)
		return;
	float fCenterX = pTexInfo->tImageInfo.Width >> 1;
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;
	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, TileInfo.vSize.x, TileInfo.vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, TileInfo.vPos.x - m_pView->GetScrollPos(SB_HORZ), TileInfo.vPos.y - m_pView->GetScrollPos(SB_VERT), 0.f);
	matWorld = matScale * matTrans;
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CTile::Render_Mini()
{
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Terrain", L"Tile", TileInfo.dwDrawID);
	if (nullptr == pTexInfo)
		return;
	float fCenterX = pTexInfo->tImageInfo.Width >> 1;
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;
	D3DXMATRIX matScale, matTrans, matWorld , matRatio;
	D3DXMatrixScaling(&matRatio, 0.3f, 0.3f, 0.f);
	D3DXMatrixScaling(&matScale, TileInfo.vSize.x, TileInfo.vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, TileInfo.vPos.x - m_pView->GetScrollPos(SB_HORZ), TileInfo.vPos.y - m_pView->GetScrollPos(SB_VERT), 0.f);
	matWorld = matScale * matTrans;
	matWorld *= matRatio;
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CTile::Release_Tile()
{
}

CTile * CTile::Create(TILE _tile)
{
	CTile* pInstance = new CTile;
	if (FAILED(pInstance->Ready_Tile(_tile)))
	{
		Safe_Delete(pInstance);
		return nullptr;
	}
	return pInstance;
}
