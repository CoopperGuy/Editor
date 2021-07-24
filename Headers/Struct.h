#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vDir;
	D3DXVECTOR3 vSize;
	//D3DXVECTOR2; 
	//D3DXVECTOR4; //x,y,z,w
}INFO;

typedef struct tagTexInfo
{
	LPDIRECT3DTEXTURE9 pTexture; // 너네가 API떄 사용했던 HBITMAP
	D3DXIMAGE_INFO tImageInfo; // 
}TEXINFO;
typedef struct tagTile
{
	D3DXVECTOR3 vPos; 
	D3DXVECTOR3 vSize; 
	DWORD dwDrawID; 
	DWORD dwOption;
}TILE;
typedef struct tagTileInfo {
	int	TileCX;
	int TileCY;
	int TileX;
	int TileY;
}TILEINFO;
typedef struct tagUnitInfo
{
#ifdef _AFX
	CString wstrName; 
#else 
	wstring wstrName; 
#endif // _AFX

	int iAtt; 
	int iDef;
	BYTE byJob; 
	BYTE byItem; 
}UNITINFO;