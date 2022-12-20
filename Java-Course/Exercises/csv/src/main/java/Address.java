public class Address {
    private String firstName;
    private String lastName;
    private String addressName;
    private String townName;
    private int townId;

    public Address(String firstName, String lastName, String addressName, String townName, int townId) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.addressName = addressName;
        this.townName = townName;
        this.townId = townId;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getAddressName() {
        return addressName;
    }

    public void setAddressName(String addressName) {
        this.addressName = addressName;
    }

    public String getTownName() {
        return townName;
    }

    public void setTownName(String townName) {
        this.townName = townName;
    }

    public int getTownId() {
        return townId;
    }

    public void setTownId(int townId) {
        this.townId = townId;
    }

    @Override
    public String toString() {
        return String.format("\nFirst name: %s\nLast name: %s\nAddress: %s\nTown name: %s\nTown id: %d\n",
                this.getFirstName(), this.getLastName(), this.getAddressName(), this.getTownName(), this.getTownId());
    }
}
