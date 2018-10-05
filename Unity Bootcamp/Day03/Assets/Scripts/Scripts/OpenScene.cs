using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class OpenScene : MonoBehaviour {

	public Texture2D cursor;

	public void Start()
	{
		Cursor.SetCursor(cursor, Vector2.zero, CursorMode.Auto);
	}

	public void LoadScene()
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
	}
}
