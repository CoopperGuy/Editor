#pragma once


#ifndef __CTILE_H__
#define __CTILE_H__
class CMFCToolView;
class CTile
{
public:
	CTile();
	~CTile();
public:
	HRESULT Ready_Tile(TILE _tile);
	void	Render_Tile();
	void	Render_Mini();
	void	Release_Tile();
public:
	void Set_View(CMFCToolView* pView) { m_pView = pView; }
	//tile settings
	void Set_Tile(TILE _tile) { TileInfo = _tile; }
	void Set_Pos(D3DXVECTOR3 _pos) { TileInfo.vPos = _pos; }
	void Set_Size(D3DXVECTOR3 _size) { TileInfo.vSize = _size; }
	void Set_Id(DWORD _id) { TileInfo.dwDrawID = _id; }
	void Set_Option(DWORD _op) { TileInfo.dwOption = _op; }
	//tile settings
public:
	D3DXVECTOR3* Get_Q() { return m_vQ; }
	TILE Get_Tile() { return TileInfo; }
	D3DXVECTOR3 Get_Pos() { return TileInfo.vPos; }
	D3DXVECTOR3 Get_Size(){return TileInfo.vSize;}
public:
	static CTile* Create(TILE _info);
private:
	TILE TileInfo;
	D3DXVECTOR3 m_vQ[4];
	D3DXVECTOR3 m_vP[4];
	CMFCToolView* m_pView;
};


#endif // !__CTILE_H__
