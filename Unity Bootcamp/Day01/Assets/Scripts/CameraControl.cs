using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraControl : MonoBehaviour {

	public Player_ex01[] players = new Player_ex01[3];
	public bool[] finished = new bool[3];
	public bool isGameWon = false;
	public List<GameObject> levels = new List<GameObject>();
	private int currentLevel = 0;
	// Use this for initialization
	void Start () {
		levels[1].SetActive(false);
		GameObject go = GameObject.Find("red");
		players[0] = go.GetComponent<Player_ex01>();
		go = GameObject.Find("yellow");
		players[1] = go.GetComponent<Player_ex01>();
		go = GameObject.Find("blue");
		players[2] = go.GetComponent<Player_ex01>();
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey("1"))
		{
			players[0].active = true;
			SetUpPlayer(0, 20f, 1f);
			DeactivateOtherPlayers(0);
		}
		if (Input.GetKey("2"))
		{
			players[1].active = true;
			SetUpPlayer(1, 25f, 1.5f);
			DeactivateOtherPlayers(1);
		}
		if (Input.GetKey("3"))
		{
			players[2].active = true;
			SetUpPlayer(2, 15f, 0.5f );
			DeactivateOtherPlayers(2);
		}
		if (Input.GetKey("backspace"))
		{
			Reset();
		}
	}

	void Reset()
	{
		players[0].ResetPosition(-7.887f, 0.727f);	
		players[1].ResetPosition(-7.46f, 0.888f);	
		players[2].ResetPosition(-6.792f, 0.877f);	
	}

	void SetUpPlayer(int i, float jump, float moveSpeed)
	{
		players[i].moveSpeed = moveSpeed;
		players[i].jumpForce = jump;
	}

	void DeactivateOtherPlayers(int j)
	{
		for(int i = 0; i < players.Length; i++)
		{
			if (i == j)
				continue;
			players[i].active = false;
		}
	}

	public void setPlayerFinished(int i)
	{
		finished[i] = true;
		int count = 0;
		for(int j = 0; j < finished.Length; j++)
		{
			if (finished[j])
				count++;
		}
		if (count == 3)
		{
			Debug.Log("Level Won");
			isGameWon = true;
			LoadNextLevel();
		}
	}

	public void NotFinished(int i)
	{
		finished[i] = false;
		isGameWon = false;
	}

	void LoadNextLevel()
	{
		if (currentLevel == 0)
		{
			levels[currentLevel].SetActive(false);
			currentLevel++;
			levels[currentLevel].SetActive(true);
			isGameWon = false;
			NotFinished(0);
			NotFinished(1);
			NotFinished(2);
			Reset();
		}
	}
}
