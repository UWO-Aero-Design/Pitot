//From aero-cpp-lib/include/Sensors.hpp


/**
 * @brief Raw pitot tube data 
 */
struct __attribute__((__packed__)) Pitot_t      //From Data.hpp
{
    int16_t differential_pressure;
};


/**
 * @brief Abstract Pitot Tube definition aka differential pressure sensor
 */ 
class Pitot
{
public:
    /** @brief Defines configuration data for the pitot tube */
    struct Config_t
    {
        // Can add things like offsets here
        // Make sure to include defaults here
    };

    /**
     * @brief Initializes the pitot tube
     * 
     * @return true if initialization was successful
     * @return false if initialization was unsuccessful
     */
    virtual bool init( ) = 0;

    /**
     * @brief Initializes the pitot tube with user configuration
     * 
     * @param config user selected pitot tube configuration
     * @return true if initialization was successful
     * @return false if initialization was unsuccessful
     */
    bool init( Pitot::Config_t config )
    {
        m_config = config;
        init();
    }

    /**
     * @brief Update the pitot tube data
     * 
     * @return true if update was successful
     * @return false if update was unsuccessful
     */
    virtual bool update( ) = 0;

    /**
     * @brief Get pitot tube data
     * 
     * @return const def::Pitot_t& reference to pitot tube's data struct
     */
    const def::Pitot_t& data(void) { return m_data; }

    /**
     * @brief Destructor
     */
    virtual ~Pitot(){}

protected:
    // Hidden constructor that only children can redefine
    Pitot(){}

    // Member variables
    def::Pitot_t m_data;      // For pitot tube data
    Pitot::Config_t m_config; // For pitot tube configuration
};
