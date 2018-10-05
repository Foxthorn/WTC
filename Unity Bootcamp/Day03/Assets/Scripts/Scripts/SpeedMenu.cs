using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SpeedMenu : MonoBehaviour {

	public GameObject speedButton;
	public Sprite[] speedButtons = new Sprite[3];
	public Texture2D cursor;

	bool paused = false;
	float speed = 0f;
	Image image;

	public void Start()
	{
		Cursor.SetCursor(cursor, Vector2.zero, CursorMode.Auto);
		image = speedButton.GetComponent<Image>();
		gameManager.gm.changeSpeed(speed + 1f);
	}

	public void PauseGame()
	{
		gameManager.gm.pause(true);
		paused = true;
	}

	public void IncreaseSpeed()
	{
		if (paused && !gameManager.gm.finished)
		{
			paused = false;
			gameManager.gm.pause(false);
			speed = 0f;
		}
		else
		{
			speed += 1f;
			if (speed >= 3f)
			{
				speed = 0f;
			}
		}
		float multiplier = speed + 1f;
		image.sprite = speedButtons[(int)speed];
		gameManager.gm.changeSpeed(speed + multiplier);
	}
}
