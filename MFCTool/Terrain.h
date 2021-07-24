#pragma once
class CMFCToolView; 
class CTile;
class CTerrain final
{
private:
	CTerrain();
public:
	~CTerrain();
public:
	vector<CTile*>& Get_TileData() { return m_vecTile; }
public:
	void Set_View(CMFCToolView* pView) { m_pView = pView;  }
	void Set_TileInfo(TILEINFO _info) { TileInfo = _info; }
	void Add_Tile(CTile* _tile) { m_vecTile.emplace_back(_tile); }
public:
	void	Tile_Change(const D3DXVECTOR3& vMouse, const DWORD& dwDrawID, const DWORD& dwOption = 0);
	int		GetTileIndex(const D3DXVECTOR3& vPos); 
	bool	IsPicking(const D3DXVECTOR3& vPos, const int& iIndex); 
public:
	HRESULT Ready_Terrain(TILEINFO _info);
	void	Render_Terrain(); 
	void	Mini_Render_Terrain(); 
	void	Release_Terrain(); 
public:
	void Delete_Tile();
public:
	static CTerrain* Create(TILEINFO _info);
private:
	vector<CTile*> m_vecTile; 
	CMFCToolView* m_pView; 
	TILEINFO TileInfo;
};

