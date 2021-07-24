#pragma once

#ifndef __CROOM_H__
#define __CROOM_H__
class CMFCToolView;
class CTerrain;
class CRoom
{
public:
	CRoom();
	~CRoom();
public:
	HRESULT Ready_Room(TILEINFO _info);
	void	Render_Room();
	void	Mini_Render_Room();
	void	Release_Room();
public:
	void Set_View(CMFCToolView* pView) { m_pView = pView; }
	void Set_TileInfo(TILEINFO _info) { TileInfo = _info; }
public:
	CTerrain* Get_Terrain() { return Terrain; }
	TILEINFO Get_TileInfo() { return TileInfo; }
public:
	void Change_Tile(const D3DXVECTOR3& vMouse, const DWORD& dwDrawID, const DWORD& dwOption = 0);
public:
	static CRoom* Create(TILEINFO _info);
private:
	CTerrain* Terrain;
	CMFCToolView* m_pView;
	TILEINFO TileInfo;
};


#endif // !__CROOM_H__
