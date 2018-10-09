using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FanSmoke : MonoBehaviour {

	public bool active;
	public float emissionRate;

	ParticleSystem exhaust;
	// Use this for initialization
	void Start () {
		exhaust = GetComponent<ParticleSystem>();
	}
	
	// Update is called once per frame
	void Update () {
		if (active)
			exhaust.emissionRate = emissionRate;
	}
}
