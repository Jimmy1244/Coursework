#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
int main()
{
    // Create the main window
	const float factorX = 480, factorY = 660;
    sf::RenderWindow window(sf::VideoMode(factorX, factorY), "SFML window");
    // Load a sprite to display	
	sf::RectangleShape rect(sf::Vector2f(420, 520));
	rect.setFillColor(sf::Color(128,42,42));
	rect.setPosition(sf::Vector2f(factorX/2 - 210,factorY/2 - 260 - 20));
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
	sprite.setScale(0.5,0.5);//default is (1,1)
	sprite.setPosition(sf::Vector2f(factorX/2 - 201,factorY/2 - 248 - 20));
    sf::Font font;
//    if (!font.loadFromFile("c:/windows/fonts/arial.ttf"))
    if (!font.loadFromFile("msjh.ttc"))
        return EXIT_FAILURE;
    sf::Text text(L"第一個SFML應用程式", font, 45);
	text.setColor(sf::Color(128,42,42));
	text.setPosition(sf::Vector2f(20, 575));
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("Reggae8-84.ogg"))
        return EXIT_FAILURE;
	sf::Vertex line1[2], line2[2];
	line1[0].position = sf::Vector2f(20,630);
	line1[0].color  = sf::Color::Yellow;
	line1[1].position = sf::Vector2f(460,630);
	line1[1].color = sf::Color::Green;
	line2[0].position = sf::Vector2f(20,640);
	line2[0].color  = sf::Color::Green;
	line2[1].position = sf::Vector2f(460,640);
	line2[1].color = sf::Color::Yellow;
    // Play the music
    music.play();
	music.setLoop(true);
	float volume = 30;
	/*std::ostringstream volumeStr;
	std::string volumeStatus = "Volume: " + std::to_string(volume);
	sf::Text textVolume(volumeStatus, font, 10);
	window.draw(textVolume);*/
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyPressed){
    			  if (event.key.code==sf::Keyboard::Escape) 
                      window.close();
				  if(music.getStatus() != sf::SoundSource::Paused){
					  if(event.key.code==sf::Keyboard::U && volume < 100){
						  volume+=10;
						  //volumeStatus;
						  music.setVolume(volume);
					  }
					  if(event.key.code==sf::Keyboard::D && volume > 0){
						  volume-=10;
						  music.setVolume(volume);
					  }
					  if(event.key.code==sf::Keyboard::P){
						  music.pause();
						  
					  }
				  }
				  else if(event.key.code==sf::Keyboard::P){					   
						  music.play();
				  }
			}
        }
        // Clear screen
        window.clear();
        // Draw the sprite
		window.draw(rect);
        window.draw(sprite);		
        // Draw the string
        window.draw(text);
		window.draw(line1,2,sf::LinesStrip);
		window.draw(line2,2,sf::LinesStrip);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}