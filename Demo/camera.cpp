#include "Camera.h"
#include "window.h"
#include "renderer.h"


Camera::Camera()
{
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&proj);
}

void Camera::Render(LPDIRECT3DDEVICE9 device)
{
	D3DXMatrixLookAtLH(&view, &position, &(position + D3DXVECTOR3{ 0, 0, 1 }), &up);
	D3DXMatrixPerspectiveFovLH(&proj, D3DXToRadian(fowy), (float)getWindowWidth() / (float)getWindowHeight(), 0.1f, 10000.0f);

	device->SetTransform(D3DTS_VIEW, &view);
	device->SetTransform(D3DTS_PROJECTION, &proj);
}

void Camera::Yaw(float units)
{
}

void Camera::Pitch(float units)
{
}

void Camera::Roll(float units)
{
}

void Camera::MoveTo(D3DXVECTOR3 point)
{
	position = point;
}

void Camera::Move(D3DXVECTOR3 vector)
{
	position += vector;
}

void Camera::Strafe(float units)
{
	position += (right * units);
}

void Camera::Fly(float units)
{
	position += (up * units);
}

void Camera::Walk(float units)
{
	position += (front * units);
}

void Camera::Zoom(float degree)
{
	fowy += degree;
}
