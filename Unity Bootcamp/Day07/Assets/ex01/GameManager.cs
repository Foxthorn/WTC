﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

	AudioSource sound;
	// Use this for initialization
	void Start () {
		sound = GetComponent<AudioSource>();
		sound.Play(0);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
