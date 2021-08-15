using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class OnTriggerLoadLevel : MonoBehaviour
{
    void OnCollisionEnter(Collision collider)
    {
        if (collider.gameObject.tag == "Player")
        {
            SceneManager.LoadScene("Day1Intro");
        }
    }
}