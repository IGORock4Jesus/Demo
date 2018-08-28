#pragma once

#include <d3dx9.h>


class Camera {

	D3DXVECTOR3 right{ 1,0,0 }, up{ 0,1,0 }, front{ 0,0,1 };
	D3DXVECTOR3 position{ 0,0,0 };
	D3DXMATRIX view, proj;
	float fowy = 90.0f;

public:
	Camera();

	void Render(LPDIRECT3DDEVICE9 device);

	void Yaw(float units);
	void Pitch(float units);
	void Roll(float units);

	void MoveTo(D3DXVECTOR3 point);
	void Move(D3DXVECTOR3 vector);

	void Strafe(float units);
	void Fly(float units);
	void Walk(float units);

	void Zoom(float degree);
};