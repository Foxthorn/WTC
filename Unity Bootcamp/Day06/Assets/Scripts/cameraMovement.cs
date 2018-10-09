using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraMovement : MonoBehaviour {

    public float rotationSpeed;
    public float speed;
    public float gravity = -1f;
	public bool holdingKeycard = false;

	public static cameraMovement cm;
 
    float pitch;
    float yaw;
    float horizontal;
    float vertical;
	Vector3 movement;
	CharacterController character;

	void Start()
	{
		character = GetComponent<CharacterController>();
		if (cm == null)
			cm = this;
	}
   
    void FixedUpdate()
    {
		MoveAndRotate();
    }

	void MoveAndRotate()
	{
        pitch += rotationSpeed * -Input.GetAxis("Mouse Y");
        yaw += rotationSpeed * Input.GetAxis("Mouse X");
		horizontal = Input.GetAxis("Horizontal") * speed;
		vertical = Input.GetAxis("Vertical") * speed;

        // Clamp pitch:
        pitch = Mathf.Clamp(pitch, -45f, 45f);
       
        // Wrap yaw:
        while (yaw < 0f) {
            yaw += 360f;
        }
        while (yaw >= 360f) {
            yaw -= 360f;
        }
       
        // Set orientation:
        transform.eulerAngles = new Vector3(pitch, yaw, 0f);
		if (horizontal != 0 || vertical != 0)
		{
			movement = new Vector3(horizontal, 0f, vertical);
			movement *= Time.deltaTime;
			movement = transform.TransformDirection(movement);
		}
		movement.y = gravity * Time.deltaTime;
		character.Move(movement);

	}
}
