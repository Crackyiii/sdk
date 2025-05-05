	static FVector2D ProjectWorldToScreen(FVector WorldLocation)
	{
		cam_position = GetPlayerView();

		if (WorldLocation.x == 0) return FVector2D(0, 0);

		_MATRIX tempMatrix = Matrix(cam_position.rotation);
		FVector vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		FVector vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		FVector vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);
		FVector vDelta = WorldLocation - cam_position.location;
		FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

		if (vTransformed.z < 1.f) vTransformed.z = 1.f;

		return FVector2D((window.ScreenWidth / 2.0f) + vTransformed.x * (((window.ScreenWidth / 2.0f) / tanf(cam_position.fov * (float)M_PI / 360.f))) / vTransformed.z, (window.ScreenHeight / 2.0f) - vTransformed.y * (((window.ScreenWidth / 2.0f) / tanf(cam_position.fov * (float)M_PI / 360.f))) / vTransformed.z);
	}