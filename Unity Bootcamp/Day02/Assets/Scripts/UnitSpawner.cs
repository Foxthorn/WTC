using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitSpawner : MonoBehaviour {

	public Transform location;
	public GameObject unit;
	// Use this for initialization
	void Start () {
		 InvokeRepeating("Spawn", 10.0f, 10.0f);
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void Spawn()
	{
		Instantiate(unit, location.position, Quaternion.identity);
	}
}
