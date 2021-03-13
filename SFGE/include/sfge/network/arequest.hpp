#pragma once

class ARequest
{
public:
  ARequest() {}
  virtual ~ARequest() = default;

  // to_bytearray() const;

protected:
  // virtual get_body() const = 0;

private:
  // request_id;
  // message_id;

  // message_type (non, con, ack, error)
};