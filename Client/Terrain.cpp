#include "stdafx.h"
#include "Terrain.h"



CTerrain::CTerrain()
{
}


CTerrain::~CTerrain()
{
	Release_GameObject(); 
}

CTerrain * CTerrain::Create()
{
	CTerrain* pInstance = new CTerrain; 
	if (FAILED(pInstance->Ready_GameObject()))
	{
		Safe_Delete(pInstance); 
		return nullptr;
	}
	return pInstance;
}

HRESULT CTerrain::LoadTileData(const wstring & wstrFilePath)
{
	HANDLE hFile = CreateFile(wstrFilePath.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr); 
	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL; 

	if (!m_vecTile.empty())
	{
		for (auto& pTile : m_vecTile)
			Safe_Delete(pTile); 
		m_vecTile.clear(); 
	}
	DWORD dwByte = 0; 
	TILE* pTile = nullptr; 
	while (true)
	{
		pTile = new TILE; 
		ReadFile(hFile, pTile, sizeof(TILE), &dwByte, nullptr); 
		if (0 == dwByte)
		{
			Safe_Delete(pTile); 
			break;;
		}
		m_vecTile.emplace_back(pTile);
	}

	CloseHandle(hFile); 
	return S_OK;
}

HRESULT CTerrain::Ready_GameObject()
{
	if (FAILED(LoadTileData(L"../Data/TileData.dat")))
		return E_FAIL; 
	return S_OK;
}

int CTerrain::Update_GameObject()
{
	float fSpeed = 300.f * CTime_Manager::Get_Instance()->Get_DeltaTime(); 
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		CScroll_Manager::Set_Scroll({ fSpeed, 0.f, 0.f });
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		CScroll_Manager::Set_Scroll({ -fSpeed, 0.f, 0.f });
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		CScroll_Manager::Set_Scroll({ 0.f, fSpeed,  0.f });
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		CScroll_Manager::Set_Scroll({ 0.f, -fSpeed,  0.f });

	// 속도 . 거리 / 시간. 

	return 0;
}

void CTerrain::Late_Update_GameObject()
{
}

void CTerrain::Render_GameObject()
{

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			int iIndex = j + (i * TILEX);
			if (0 > iIndex || m_vecTile.size() <= iIndex)
				return;
			const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Terrain", L"Tile", m_vecTile[iIndex]->dwDrawID);
			if (nullptr == pTexInfo)
				return;
			float fCenterX = pTexInfo->tImageInfo.Width >> 1;
			float fCenterY = pTexInfo->tImageInfo.Height >> 1;
			D3DXMATRIX matScale, matTrans, matWorld;
			D3DXMatrixScaling(&matScale, m_vecTile[iIndex]->vSize.x, m_vecTile[iIndex]->vSize.y, 0.f);
			D3DXMatrixTranslation(&matTrans, m_vecTile[iIndex]->vPos.x + CScroll_Manager::Get_Scroll(CScroll_Manager::HORZ_SCROLL), m_vecTile[iIndex]->vPos.y + CScroll_Manager::Get_Scroll(CScroll_Manager::VERT_SCROLL), 0.f);
			matWorld = matScale * matTrans;
			CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
			CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
	}
}

void CTerrain::Release_GameObject()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), Safe_Delete<TILE*>);
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}
